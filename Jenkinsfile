#!/usr/bin/groovy
/* groovylint-disable-next-line LineLength */
/* groovylint-disable DuplicateMapLiteral, DuplicateNumberLiteral */
/* groovylint-disable DuplicateStringLiteral, NestedBlockDepth, VariableName */
/* Copyright 2019-2023 Intel Corporation
 * All rights reserved.
 *
 * This file is part of the DAOS Project. It is subject to the license terms
 * in the LICENSE file found in the top-level directory of this distribution
 * and at https://img.shields.io/badge/License-BSD--2--Clause--Patent-blue.svg.
 * No part of the DAOS Project, including this file, may be copied, modified,
 * propagated, or distributed except according to the terms contained in the
 * LICENSE file.
 */

// To use a test branch (i.e. PR) until it lands to master
// I.e. for testing library changes
//@Library(value='pipeline-lib@your_branch') _

/* groovylint-disable-next-line CompileStatic */
job_status_internal = [:]

void job_status_write() {
    if (!env.DAOS_STACK_JOB_STATUS_DIR) {
        return
    }
    String jobName = env.JOB_NAME.replace('/', '_')
    jobName += '_' + env.BUILD_NUMBER
    String fileName = env.DAOS_STACK_JOB_STATUS_DIR + '/' + jobName

    String job_status_text = writeYaml data: job_status_internal,
                                       returnText: true

    // Need to use shell script for creating files that are not
    // in the workspace.
    sh label: "Write jenkins_job_status ${fileName}",
       script: "echo \"${job_status_text}\" >> ${fileName}"
}

// groovylint-disable-next-line MethodParameterTypeRequired
void job_status_update(String name=env.STAGE_NAME,
                       // groovylint-disable-next-line NoDef
                       def value=currentBuild.currentResult) {
    String key = name.replace(' ', '_')
    key = key.replaceAll('[ .]', '_')
    job_status_internal[key] = value
}

// groovylint-disable-next-line MethodParameterTypeRequired, NoDef
void job_step_update(def value) {
    // Wrapper around a pipeline step to obtain a status.
    job_status_update(env.STAGE_NAME, value)
}

// For master, this is just some wildly high number
/* groovylint-disable-next-line CompileStatic */
String next_version = '2.3'

// Don't define this as a type or it loses it's global scope
target_branch = env.CHANGE_TARGET ? env.CHANGE_TARGET : env.BRANCH_NAME
String sanitized_JOB_NAME = JOB_NAME.toLowerCase().replaceAll('/', '-').replaceAll('%2f', '-')

// bail out of branch builds that are not on a whitelist
if (!env.CHANGE_ID &&
    (!env.BRANCH_NAME.startsWith('weekly-testing') &&
     !env.BRANCH_NAME.startsWith('release/') &&
     !env.BRANCH_NAME.startsWith('ci-') &&
     env.BRANCH_NAME != 'master')) {
    currentBuild.result = 'SUCCESS'
    return
}

// The docker agent setup and the provisionNodes step need to know the
// UID that the build agent is running under.
cached_uid = 0
Integer getuid() {
    if (cached_uid == 0) {
        cached_uid = sh(label: 'getuid()',
                        script: 'id -u',
                        returnStdout: true).trim()
    }
    return cached_uid
}

pipeline {
    agent { label 'lightweight' }

