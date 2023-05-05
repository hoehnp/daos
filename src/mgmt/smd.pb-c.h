/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: smd.proto */

#ifndef PROTOBUF_C_smd_2eproto__INCLUDED
#define PROTOBUF_C_smd_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1003000 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _Ctl__BioHealthReq Ctl__BioHealthReq;
typedef struct _Ctl__BioHealthResp Ctl__BioHealthResp;
typedef struct _Ctl__SmdDevice Ctl__SmdDevice;
typedef struct _Ctl__SmdDevReq Ctl__SmdDevReq;
typedef struct _Ctl__SmdDevResp Ctl__SmdDevResp;
typedef struct _Ctl__SmdPoolReq Ctl__SmdPoolReq;
typedef struct _Ctl__SmdPoolResp Ctl__SmdPoolResp;
typedef struct _Ctl__SmdPoolResp__Pool Ctl__SmdPoolResp__Pool;
typedef struct _Ctl__SmdQueryReq Ctl__SmdQueryReq;
typedef struct _Ctl__SmdQueryResp Ctl__SmdQueryResp;
typedef struct _Ctl__SmdQueryResp__SmdDeviceWithHealth Ctl__SmdQueryResp__SmdDeviceWithHealth;
typedef struct _Ctl__SmdQueryResp__Pool Ctl__SmdQueryResp__Pool;
typedef struct _Ctl__SmdQueryResp__RankResp Ctl__SmdQueryResp__RankResp;
typedef struct _Ctl__LedManageReq Ctl__LedManageReq;
typedef struct _Ctl__DevReplaceReq Ctl__DevReplaceReq;
typedef struct _Ctl__SetFaultyReq Ctl__SetFaultyReq;
typedef struct _Ctl__DevManageResp Ctl__DevManageResp;
typedef struct _Ctl__SmdManageReq Ctl__SmdManageReq;
typedef struct _Ctl__SmdManageResp Ctl__SmdManageResp;
typedef struct _Ctl__SmdManageResp__Result Ctl__SmdManageResp__Result;
typedef struct _Ctl__SmdManageResp__RankResp Ctl__SmdManageResp__RankResp;


/* --- enums --- */

typedef enum _Ctl__NvmeDevState {
  /*
   * Device is in a normal operational state
   */
  CTL__NVME_DEV_STATE__NORMAL = 0,
  /*
   * Device is new and is not yet in-use
   */
  CTL__NVME_DEV_STATE__NEW = 1,
  /*
   * Device is faulty and has been evicted
   */
  CTL__NVME_DEV_STATE__EVICTED = 2,
  /*
   * Device has been physically removed
   */
  CTL__NVME_DEV_STATE__UNPLUGGED = 3
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(CTL__NVME_DEV_STATE)
} Ctl__NvmeDevState;
typedef enum _Ctl__LedState {
  /*
   * Equivalent to SPDK_VMD_LED_STATE_OFF
   */
  CTL__LED_STATE__OFF = 0,
  /*
   * Equivalent to SPDK_VMD_LED_STATE_IDENTIFY	(4Hz blink)
   */
  CTL__LED_STATE__QUICK_BLINK = 1,
  /*
   * Equivalent to SPDK_VMD_LED_STATE_FAULT	(solid on)
   */
  CTL__LED_STATE__ON = 2,
  /*
   * Equivalent to SPDK_VMD_LED_STATE_REBUILD	(1Hz blink)
   */
  CTL__LED_STATE__SLOW_BLINK = 3,
  /*
   * Equivalent to SPDK_VMD_LED_STATE_UNKNOWN	(VMD not enabled)
   */
  CTL__LED_STATE__NA = 4
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(CTL__LED_STATE)
} Ctl__LedState;
typedef enum _Ctl__LedAction {
  CTL__LED_ACTION__GET = 0,
  CTL__LED_ACTION__SET = 1,
  CTL__LED_ACTION__RESET = 2
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(CTL__LED_ACTION)
} Ctl__LedAction;

/* --- messages --- */

struct  _Ctl__BioHealthReq
{
  ProtobufCMessage base;
  char *dev_uuid;
};
#define CTL__BIO_HEALTH_REQ__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ctl__bio_health_req__descriptor) \
    , (char *)protobuf_c_empty_string }


/*
 * BioHealthResp mirrors nvme_health_stats structure.
 */
struct  _Ctl__BioHealthResp
{
  ProtobufCMessage base;
  uint64_t timestamp;
  /*
   * Device health details
   */
  uint32_t warn_temp_time;
  uint32_t crit_temp_time;
  uint64_t ctrl_busy_time;
  uint64_t power_cycles;
  uint64_t power_on_hours;
  uint64_t unsafe_shutdowns;
  uint64_t media_errs;
  uint64_t err_log_entries;
  /*
   * I/O error counters
   */
  uint32_t bio_read_errs;
  uint32_t bio_write_errs;
  uint32_t bio_unmap_errs;
  uint32_t checksum_errs;
  /*
   * in Kelvin
   */
  uint32_t temperature;
  /*
   * Critical warnings
   */
  protobuf_c_boolean temp_warn;
  protobuf_c_boolean avail_spare_warn;
  protobuf_c_boolean dev_reliability_warn;
  protobuf_c_boolean read_only_warn;
  /*
   * volatile memory backup
   */
  protobuf_c_boolean volatile_mem_warn;
  /*
   * DAOS err code
   */
  int32_t status;
  /*
   * UUID of blobstore
   */
  char *dev_uuid;
  /*
   * Usage stats
   */
  /*
   * size of blobstore
   */
  uint64_t total_bytes;
  /*
   * free space in blobstore
   */
  uint64_t avail_bytes;
  /*
   * Intel vendor SMART attributes
   */
  /*
   * percent remaining
   */
  uint32_t program_fail_cnt_norm;
  /*
   * current value
   */
  uint64_t program_fail_cnt_raw;
  uint32_t erase_fail_cnt_norm;
  uint64_t erase_fail_cnt_raw;
  uint32_t wear_leveling_cnt_norm;
  uint32_t wear_leveling_cnt_min;
  uint32_t wear_leveling_cnt_max;
  uint32_t wear_leveling_cnt_avg;
  uint64_t endtoend_err_cnt_raw;
  uint64_t crc_err_cnt_raw;
  uint64_t media_wear_raw;
  uint64_t host_reads_raw;
  uint64_t workload_timer_raw;
  uint32_t thermal_throttle_status;
  uint64_t thermal_throttle_event_cnt;
  uint64_t retry_buffer_overflow_cnt;
  uint64_t pll_lock_loss_cnt;
  uint64_t nand_bytes_written;
  uint64_t host_bytes_written;
  /*
   * Engine configs properties
   */
  /*
   * blobstore cluster size in bytes
   */
  uint64_t cluster_size;
};
#define CTL__BIO_HEALTH_RESP__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ctl__bio_health_resp__descriptor) \
    , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (char *)protobuf_c_empty_string, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }


/*
 * SmdDevice represents a DAOS BIO device, identified by a UUID written into a label stored on a
 * SPDK blobstore created on a NVMe namespace. Multiple SmdDevices may exist per NVMe controller.
 */
struct  _Ctl__SmdDevice
{
  ProtobufCMessage base;
  /*
   * UUID of blobstore
   */
  char *uuid;
  /*
   * VOS target IDs
   */
  size_t n_tgt_ids;
  int32_t *tgt_ids;
  /*
   * Transport address of blobstore
   */
  char *tr_addr;
  /*
   * NVMe device state
   */
  Ctl__NvmeDevState dev_state;
  /*
   * LED state
   */
  Ctl__LedState led_state;
  /*
   * blobstore clusters total bytes
   */
  uint64_t total_bytes;
  /*
   * blobstore clusters available bytes
   */
  uint64_t avail_bytes;
  /*
   * blobstore cluster size in bytes
   */
  uint64_t cluster_size;
  /*
   * DAOS I/O Engine using controller
   */
  uint32_t rank;
};
#define CTL__SMD_DEVICE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ctl__smd_device__descriptor) \
    , (char *)protobuf_c_empty_string, 0,NULL, (char *)protobuf_c_empty_string, CTL__NVME_DEV_STATE__NORMAL, CTL__LED_STATE__OFF, 0, 0, 0, 0 }


struct  _Ctl__SmdDevReq
{
  ProtobufCMessage base;
};
#define CTL__SMD_DEV_REQ__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ctl__smd_dev_req__descriptor) \
     }


struct  _Ctl__SmdDevResp
{
  ProtobufCMessage base;
  int32_t status;
  size_t n_devices;
  Ctl__SmdDevice **devices;
};
#define CTL__SMD_DEV_RESP__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ctl__smd_dev_resp__descriptor) \
    , 0, 0,NULL }


struct  _Ctl__SmdPoolReq
{
  ProtobufCMessage base;
};
#define CTL__SMD_POOL_REQ__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ctl__smd_pool_req__descriptor) \
     }


struct  _Ctl__SmdPoolResp__Pool
{
  ProtobufCMessage base;
  /*
   * UUID of VOS pool
   */
  char *uuid;
  /*
   * VOS target IDs
   */
  size_t n_tgt_ids;
  int32_t *tgt_ids;
  /*
   * SPDK blobs
   */
  size_t n_blobs;
  uint64_t *blobs;
};
#define CTL__SMD_POOL_RESP__POOL__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ctl__smd_pool_resp__pool__descriptor) \
    , (char *)protobuf_c_empty_string, 0,NULL, 0,NULL }


struct  _Ctl__SmdPoolResp
{
  ProtobufCMessage base;
  int32_t status;
  size_t n_pools;
  Ctl__SmdPoolResp__Pool **pools;
};
#define CTL__SMD_POOL_RESP__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ctl__smd_pool_resp__descriptor) \
    , 0, 0,NULL }


struct  _Ctl__SmdQueryReq
{
  ProtobufCMessage base;
  /*
   * Indicate query should omit devices
   */
  protobuf_c_boolean omit_devices;
  /*
   * Indicate query should omit pools
   */
  protobuf_c_boolean omit_pools;
  /*
   * Indicate query should include BIO health for devices
   */
  protobuf_c_boolean include_bio_health;
  /*
   * Constrain query to this UUID (pool or device)
   */
  char *uuid;
  /*
   * Restrict response to only include info about this rank
   */
  uint32_t rank;
};
#define CTL__SMD_QUERY_REQ__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ctl__smd_query_req__descriptor) \
    , 0, 0, 0, (char *)protobuf_c_empty_string, 0 }


struct  _Ctl__SmdQueryResp__SmdDeviceWithHealth
{
  ProtobufCMessage base;
  Ctl__SmdDevice *details;
  /*
   * optional BIO health
   */
  Ctl__BioHealthResp *health;
};
#define CTL__SMD_QUERY_RESP__SMD_DEVICE_WITH_HEALTH__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ctl__smd_query_resp__smd_device_with_health__descriptor) \
    , NULL, NULL }


struct  _Ctl__SmdQueryResp__Pool
{
  ProtobufCMessage base;
  /*
   * UUID of VOS pool
   */
  char *uuid;
  /*
   * VOS target IDs
   */
  size_t n_tgt_ids;
  int32_t *tgt_ids;
  /*
   * SPDK blobs
   */
  size_t n_blobs;
  uint64_t *blobs;
};
#define CTL__SMD_QUERY_RESP__POOL__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ctl__smd_query_resp__pool__descriptor) \
    , (char *)protobuf_c_empty_string, 0,NULL, 0,NULL }


struct  _Ctl__SmdQueryResp__RankResp
{
  ProtobufCMessage base;
  /*
   * rank to which this response corresponds
   */
  uint32_t rank;
  /*
   * List of devices on the rank
   */
  size_t n_devices;
  Ctl__SmdQueryResp__SmdDeviceWithHealth **devices;
  /*
   * List of pools on the rank
   */
  size_t n_pools;
  Ctl__SmdQueryResp__Pool **pools;
};
#define CTL__SMD_QUERY_RESP__RANK_RESP__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ctl__smd_query_resp__rank_resp__descriptor) \
    , 0, 0,NULL, 0,NULL }


struct  _Ctl__SmdQueryResp
{
  ProtobufCMessage base;
  /*
   * DAOS error code
   */
  int32_t status;
  /*
   * List of per-rank responses
   */
  size_t n_ranks;
  Ctl__SmdQueryResp__RankResp **ranks;
};
#define CTL__SMD_QUERY_RESP__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ctl__smd_query_resp__descriptor) \
    , 0, 0,NULL }


struct  _Ctl__LedManageReq
{
  ProtobufCMessage base;
  /*
   * List of Device-UUIDs and/or PCI-addresses
   */
  char *ids;
  /*
   * LED action to perform
   */
  Ctl__LedAction led_action;
  /*
   * LED state to set (used if action is SET)
   */
  Ctl__LedState led_state;
  /*
   * LED action duration (how long to blink LED in minutes)
   */
  uint32_t led_duration_mins;
};
#define CTL__LED_MANAGE_REQ__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ctl__led_manage_req__descriptor) \
    , (char *)protobuf_c_empty_string, CTL__LED_ACTION__GET, CTL__LED_STATE__OFF, 0 }


struct  _Ctl__DevReplaceReq
{
  ProtobufCMessage base;
  /*
   * UUID of old (hot-removed) blobstore/device
   */
  char *old_dev_uuid;
  /*
   * UUID of new (hot-plugged) blobstore/device
   */
  char *new_dev_uuid;
  /*
   * Skip device reintegration if set
   */
  protobuf_c_boolean no_reint;
};
#define CTL__DEV_REPLACE_REQ__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ctl__dev_replace_req__descriptor) \
    , (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, 0 }


struct  _Ctl__SetFaultyReq
{
  ProtobufCMessage base;
  /*
   * Device-UUID (as recorded in SMD)
   */
  char *uuid;
};
#define CTL__SET_FAULTY_REQ__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ctl__set_faulty_req__descriptor) \
    , (char *)protobuf_c_empty_string }


struct  _Ctl__DevManageResp
{
  ProtobufCMessage base;
  /*
   * DAOS error code
   */
  int32_t status;
  /*
   * Details of device that has been managed
   */
  Ctl__SmdDevice *device;
};
#define CTL__DEV_MANAGE_RESP__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ctl__dev_manage_resp__descriptor) \
    , 0, NULL }


typedef enum {
  CTL__SMD_MANAGE_REQ__OP__NOT_SET = 0,
  CTL__SMD_MANAGE_REQ__OP_LED = 1,
  CTL__SMD_MANAGE_REQ__OP_REPLACE = 2,
  CTL__SMD_MANAGE_REQ__OP_FAULTY = 3
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(CTL__SMD_MANAGE_REQ__OP)
} Ctl__SmdManageReq__OpCase;

struct  _Ctl__SmdManageReq
{
  ProtobufCMessage base;
  Ctl__SmdManageReq__OpCase op_case;
  union {
    /*
     * Request to manage LED state
     */
    Ctl__LedManageReq *led;
    /*
     * Request to replace SMD device
     */
    Ctl__DevReplaceReq *replace;
    /*
     * Request to set SMD device faulty
     */
    Ctl__SetFaultyReq *faulty;
  };
};
#define CTL__SMD_MANAGE_REQ__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ctl__smd_manage_req__descriptor) \
    , CTL__SMD_MANAGE_REQ__OP__NOT_SET, {0} }


struct  _Ctl__SmdManageResp__Result
{
  ProtobufCMessage base;
  /*
   * DAOS error code
   */
  int32_t status;
  Ctl__SmdDevice *device;
};
#define CTL__SMD_MANAGE_RESP__RESULT__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ctl__smd_manage_resp__result__descriptor) \
    , 0, NULL }


struct  _Ctl__SmdManageResp__RankResp
{
  ProtobufCMessage base;
  /*
   * Rank to which this response corresponds
   */
  uint32_t rank;
  /*
   * List of device results on the rank
   */
  size_t n_results;
  Ctl__SmdManageResp__Result **results;
};
#define CTL__SMD_MANAGE_RESP__RANK_RESP__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ctl__smd_manage_resp__rank_resp__descriptor) \
    , 0, 0,NULL }


struct  _Ctl__SmdManageResp
{
  ProtobufCMessage base;
  /*
   * List of per-rank responses
   */
  size_t n_ranks;
  Ctl__SmdManageResp__RankResp **ranks;
};
#define CTL__SMD_MANAGE_RESP__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&ctl__smd_manage_resp__descriptor) \
    , 0,NULL }


/* Ctl__BioHealthReq methods */
void   ctl__bio_health_req__init
                     (Ctl__BioHealthReq         *message);
size_t ctl__bio_health_req__get_packed_size
                     (const Ctl__BioHealthReq   *message);
size_t ctl__bio_health_req__pack
                     (const Ctl__BioHealthReq   *message,
                      uint8_t             *out);
size_t ctl__bio_health_req__pack_to_buffer
                     (const Ctl__BioHealthReq   *message,
                      ProtobufCBuffer     *buffer);
Ctl__BioHealthReq *
       ctl__bio_health_req__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   ctl__bio_health_req__free_unpacked
                     (Ctl__BioHealthReq *message,
                      ProtobufCAllocator *allocator);
/* Ctl__BioHealthResp methods */
void   ctl__bio_health_resp__init
                     (Ctl__BioHealthResp         *message);
size_t ctl__bio_health_resp__get_packed_size
                     (const Ctl__BioHealthResp   *message);
size_t ctl__bio_health_resp__pack
                     (const Ctl__BioHealthResp   *message,
                      uint8_t             *out);
size_t ctl__bio_health_resp__pack_to_buffer
                     (const Ctl__BioHealthResp   *message,
                      ProtobufCBuffer     *buffer);
Ctl__BioHealthResp *
       ctl__bio_health_resp__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   ctl__bio_health_resp__free_unpacked
                     (Ctl__BioHealthResp *message,
                      ProtobufCAllocator *allocator);
/* Ctl__SmdDevice methods */
void   ctl__smd_device__init
                     (Ctl__SmdDevice         *message);
size_t ctl__smd_device__get_packed_size
                     (const Ctl__SmdDevice   *message);
size_t ctl__smd_device__pack
                     (const Ctl__SmdDevice   *message,
                      uint8_t             *out);
size_t ctl__smd_device__pack_to_buffer
                     (const Ctl__SmdDevice   *message,
                      ProtobufCBuffer     *buffer);
Ctl__SmdDevice *
       ctl__smd_device__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   ctl__smd_device__free_unpacked
                     (Ctl__SmdDevice *message,
                      ProtobufCAllocator *allocator);
/* Ctl__SmdDevReq methods */
void   ctl__smd_dev_req__init
                     (Ctl__SmdDevReq         *message);
size_t ctl__smd_dev_req__get_packed_size
                     (const Ctl__SmdDevReq   *message);
size_t ctl__smd_dev_req__pack
                     (const Ctl__SmdDevReq   *message,
                      uint8_t             *out);
size_t ctl__smd_dev_req__pack_to_buffer
                     (const Ctl__SmdDevReq   *message,
                      ProtobufCBuffer     *buffer);
Ctl__SmdDevReq *
       ctl__smd_dev_req__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   ctl__smd_dev_req__free_unpacked
                     (Ctl__SmdDevReq *message,
                      ProtobufCAllocator *allocator);
/* Ctl__SmdDevResp methods */
void   ctl__smd_dev_resp__init
                     (Ctl__SmdDevResp         *message);
size_t ctl__smd_dev_resp__get_packed_size
                     (const Ctl__SmdDevResp   *message);
size_t ctl__smd_dev_resp__pack
                     (const Ctl__SmdDevResp   *message,
                      uint8_t             *out);
size_t ctl__smd_dev_resp__pack_to_buffer
                     (const Ctl__SmdDevResp   *message,
                      ProtobufCBuffer     *buffer);
Ctl__SmdDevResp *
       ctl__smd_dev_resp__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   ctl__smd_dev_resp__free_unpacked
                     (Ctl__SmdDevResp *message,
                      ProtobufCAllocator *allocator);
/* Ctl__SmdPoolReq methods */
void   ctl__smd_pool_req__init
                     (Ctl__SmdPoolReq         *message);
size_t ctl__smd_pool_req__get_packed_size
                     (const Ctl__SmdPoolReq   *message);
size_t ctl__smd_pool_req__pack
                     (const Ctl__SmdPoolReq   *message,
                      uint8_t             *out);
size_t ctl__smd_pool_req__pack_to_buffer
                     (const Ctl__SmdPoolReq   *message,
                      ProtobufCBuffer     *buffer);
Ctl__SmdPoolReq *
       ctl__smd_pool_req__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   ctl__smd_pool_req__free_unpacked
                     (Ctl__SmdPoolReq *message,
                      ProtobufCAllocator *allocator);
/* Ctl__SmdPoolResp__Pool methods */
void   ctl__smd_pool_resp__pool__init
                     (Ctl__SmdPoolResp__Pool         *message);
/* Ctl__SmdPoolResp methods */
void   ctl__smd_pool_resp__init
                     (Ctl__SmdPoolResp         *message);
size_t ctl__smd_pool_resp__get_packed_size
                     (const Ctl__SmdPoolResp   *message);
size_t ctl__smd_pool_resp__pack
                     (const Ctl__SmdPoolResp   *message,
                      uint8_t             *out);
size_t ctl__smd_pool_resp__pack_to_buffer
                     (const Ctl__SmdPoolResp   *message,
                      ProtobufCBuffer     *buffer);
Ctl__SmdPoolResp *
       ctl__smd_pool_resp__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   ctl__smd_pool_resp__free_unpacked
                     (Ctl__SmdPoolResp *message,
                      ProtobufCAllocator *allocator);
/* Ctl__SmdQueryReq methods */
void   ctl__smd_query_req__init
                     (Ctl__SmdQueryReq         *message);
size_t ctl__smd_query_req__get_packed_size
                     (const Ctl__SmdQueryReq   *message);
size_t ctl__smd_query_req__pack
                     (const Ctl__SmdQueryReq   *message,
                      uint8_t             *out);
size_t ctl__smd_query_req__pack_to_buffer
                     (const Ctl__SmdQueryReq   *message,
                      ProtobufCBuffer     *buffer);
Ctl__SmdQueryReq *
       ctl__smd_query_req__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   ctl__smd_query_req__free_unpacked
                     (Ctl__SmdQueryReq *message,
                      ProtobufCAllocator *allocator);
/* Ctl__SmdQueryResp__SmdDeviceWithHealth methods */
void   ctl__smd_query_resp__smd_device_with_health__init
                     (Ctl__SmdQueryResp__SmdDeviceWithHealth         *message);
/* Ctl__SmdQueryResp__Pool methods */
void   ctl__smd_query_resp__pool__init
                     (Ctl__SmdQueryResp__Pool         *message);
/* Ctl__SmdQueryResp__RankResp methods */
void   ctl__smd_query_resp__rank_resp__init
                     (Ctl__SmdQueryResp__RankResp         *message);
/* Ctl__SmdQueryResp methods */
void   ctl__smd_query_resp__init
                     (Ctl__SmdQueryResp         *message);
size_t ctl__smd_query_resp__get_packed_size
                     (const Ctl__SmdQueryResp   *message);
size_t ctl__smd_query_resp__pack
                     (const Ctl__SmdQueryResp   *message,
                      uint8_t             *out);
size_t ctl__smd_query_resp__pack_to_buffer
                     (const Ctl__SmdQueryResp   *message,
                      ProtobufCBuffer     *buffer);
Ctl__SmdQueryResp *
       ctl__smd_query_resp__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   ctl__smd_query_resp__free_unpacked
                     (Ctl__SmdQueryResp *message,
                      ProtobufCAllocator *allocator);
/* Ctl__LedManageReq methods */
void   ctl__led_manage_req__init
                     (Ctl__LedManageReq         *message);
size_t ctl__led_manage_req__get_packed_size
                     (const Ctl__LedManageReq   *message);
size_t ctl__led_manage_req__pack
                     (const Ctl__LedManageReq   *message,
                      uint8_t             *out);
size_t ctl__led_manage_req__pack_to_buffer
                     (const Ctl__LedManageReq   *message,
                      ProtobufCBuffer     *buffer);
Ctl__LedManageReq *
       ctl__led_manage_req__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   ctl__led_manage_req__free_unpacked
                     (Ctl__LedManageReq *message,
                      ProtobufCAllocator *allocator);
/* Ctl__DevReplaceReq methods */
void   ctl__dev_replace_req__init
                     (Ctl__DevReplaceReq         *message);
size_t ctl__dev_replace_req__get_packed_size
                     (const Ctl__DevReplaceReq   *message);
size_t ctl__dev_replace_req__pack
                     (const Ctl__DevReplaceReq   *message,
                      uint8_t             *out);
size_t ctl__dev_replace_req__pack_to_buffer
                     (const Ctl__DevReplaceReq   *message,
                      ProtobufCBuffer     *buffer);
Ctl__DevReplaceReq *
       ctl__dev_replace_req__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   ctl__dev_replace_req__free_unpacked
                     (Ctl__DevReplaceReq *message,
                      ProtobufCAllocator *allocator);
/* Ctl__SetFaultyReq methods */
void   ctl__set_faulty_req__init
                     (Ctl__SetFaultyReq         *message);
size_t ctl__set_faulty_req__get_packed_size
                     (const Ctl__SetFaultyReq   *message);
size_t ctl__set_faulty_req__pack
                     (const Ctl__SetFaultyReq   *message,
                      uint8_t             *out);
size_t ctl__set_faulty_req__pack_to_buffer
                     (const Ctl__SetFaultyReq   *message,
                      ProtobufCBuffer     *buffer);
Ctl__SetFaultyReq *
       ctl__set_faulty_req__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   ctl__set_faulty_req__free_unpacked
                     (Ctl__SetFaultyReq *message,
                      ProtobufCAllocator *allocator);
/* Ctl__DevManageResp methods */
void   ctl__dev_manage_resp__init
                     (Ctl__DevManageResp         *message);
size_t ctl__dev_manage_resp__get_packed_size
                     (const Ctl__DevManageResp   *message);
size_t ctl__dev_manage_resp__pack
                     (const Ctl__DevManageResp   *message,
                      uint8_t             *out);
size_t ctl__dev_manage_resp__pack_to_buffer
                     (const Ctl__DevManageResp   *message,
                      ProtobufCBuffer     *buffer);
Ctl__DevManageResp *
       ctl__dev_manage_resp__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   ctl__dev_manage_resp__free_unpacked
                     (Ctl__DevManageResp *message,
                      ProtobufCAllocator *allocator);
/* Ctl__SmdManageReq methods */
void   ctl__smd_manage_req__init
                     (Ctl__SmdManageReq         *message);
size_t ctl__smd_manage_req__get_packed_size
                     (const Ctl__SmdManageReq   *message);
size_t ctl__smd_manage_req__pack
                     (const Ctl__SmdManageReq   *message,
                      uint8_t             *out);
size_t ctl__smd_manage_req__pack_to_buffer
                     (const Ctl__SmdManageReq   *message,
                      ProtobufCBuffer     *buffer);
Ctl__SmdManageReq *
       ctl__smd_manage_req__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   ctl__smd_manage_req__free_unpacked
                     (Ctl__SmdManageReq *message,
                      ProtobufCAllocator *allocator);
/* Ctl__SmdManageResp__Result methods */
void   ctl__smd_manage_resp__result__init
                     (Ctl__SmdManageResp__Result         *message);
/* Ctl__SmdManageResp__RankResp methods */
void   ctl__smd_manage_resp__rank_resp__init
                     (Ctl__SmdManageResp__RankResp         *message);
/* Ctl__SmdManageResp methods */
void   ctl__smd_manage_resp__init
                     (Ctl__SmdManageResp         *message);
size_t ctl__smd_manage_resp__get_packed_size
                     (const Ctl__SmdManageResp   *message);
size_t ctl__smd_manage_resp__pack
                     (const Ctl__SmdManageResp   *message,
                      uint8_t             *out);
size_t ctl__smd_manage_resp__pack_to_buffer
                     (const Ctl__SmdManageResp   *message,
                      ProtobufCBuffer     *buffer);
Ctl__SmdManageResp *
       ctl__smd_manage_resp__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   ctl__smd_manage_resp__free_unpacked
                     (Ctl__SmdManageResp *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Ctl__BioHealthReq_Closure)
                 (const Ctl__BioHealthReq *message,
                  void *closure_data);
typedef void (*Ctl__BioHealthResp_Closure)
                 (const Ctl__BioHealthResp *message,
                  void *closure_data);
typedef void (*Ctl__SmdDevice_Closure)
                 (const Ctl__SmdDevice *message,
                  void *closure_data);
typedef void (*Ctl__SmdDevReq_Closure)
                 (const Ctl__SmdDevReq *message,
                  void *closure_data);
typedef void (*Ctl__SmdDevResp_Closure)
                 (const Ctl__SmdDevResp *message,
                  void *closure_data);
typedef void (*Ctl__SmdPoolReq_Closure)
                 (const Ctl__SmdPoolReq *message,
                  void *closure_data);
typedef void (*Ctl__SmdPoolResp__Pool_Closure)
                 (const Ctl__SmdPoolResp__Pool *message,
                  void *closure_data);
typedef void (*Ctl__SmdPoolResp_Closure)
                 (const Ctl__SmdPoolResp *message,
                  void *closure_data);
typedef void (*Ctl__SmdQueryReq_Closure)
                 (const Ctl__SmdQueryReq *message,
                  void *closure_data);
typedef void (*Ctl__SmdQueryResp__SmdDeviceWithHealth_Closure)
                 (const Ctl__SmdQueryResp__SmdDeviceWithHealth *message,
                  void *closure_data);
typedef void (*Ctl__SmdQueryResp__Pool_Closure)
                 (const Ctl__SmdQueryResp__Pool *message,
                  void *closure_data);
typedef void (*Ctl__SmdQueryResp__RankResp_Closure)
                 (const Ctl__SmdQueryResp__RankResp *message,
                  void *closure_data);
typedef void (*Ctl__SmdQueryResp_Closure)
                 (const Ctl__SmdQueryResp *message,
                  void *closure_data);
typedef void (*Ctl__LedManageReq_Closure)
                 (const Ctl__LedManageReq *message,
                  void *closure_data);
typedef void (*Ctl__DevReplaceReq_Closure)
                 (const Ctl__DevReplaceReq *message,
                  void *closure_data);
typedef void (*Ctl__SetFaultyReq_Closure)
                 (const Ctl__SetFaultyReq *message,
                  void *closure_data);
typedef void (*Ctl__DevManageResp_Closure)
                 (const Ctl__DevManageResp *message,
                  void *closure_data);
typedef void (*Ctl__SmdManageReq_Closure)
                 (const Ctl__SmdManageReq *message,
                  void *closure_data);
typedef void (*Ctl__SmdManageResp__Result_Closure)
                 (const Ctl__SmdManageResp__Result *message,
                  void *closure_data);
typedef void (*Ctl__SmdManageResp__RankResp_Closure)
                 (const Ctl__SmdManageResp__RankResp *message,
                  void *closure_data);
typedef void (*Ctl__SmdManageResp_Closure)
                 (const Ctl__SmdManageResp *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCEnumDescriptor    ctl__nvme_dev_state__descriptor;
extern const ProtobufCEnumDescriptor    ctl__led_state__descriptor;
extern const ProtobufCEnumDescriptor    ctl__led_action__descriptor;
extern const ProtobufCMessageDescriptor ctl__bio_health_req__descriptor;
extern const ProtobufCMessageDescriptor ctl__bio_health_resp__descriptor;
extern const ProtobufCMessageDescriptor ctl__smd_device__descriptor;
extern const ProtobufCMessageDescriptor ctl__smd_dev_req__descriptor;
extern const ProtobufCMessageDescriptor ctl__smd_dev_resp__descriptor;
extern const ProtobufCMessageDescriptor ctl__smd_pool_req__descriptor;
extern const ProtobufCMessageDescriptor ctl__smd_pool_resp__descriptor;
extern const ProtobufCMessageDescriptor ctl__smd_pool_resp__pool__descriptor;
extern const ProtobufCMessageDescriptor ctl__smd_query_req__descriptor;
extern const ProtobufCMessageDescriptor ctl__smd_query_resp__descriptor;
extern const ProtobufCMessageDescriptor ctl__smd_query_resp__smd_device_with_health__descriptor;
extern const ProtobufCMessageDescriptor ctl__smd_query_resp__pool__descriptor;
extern const ProtobufCMessageDescriptor ctl__smd_query_resp__rank_resp__descriptor;
extern const ProtobufCMessageDescriptor ctl__led_manage_req__descriptor;
extern const ProtobufCMessageDescriptor ctl__dev_replace_req__descriptor;
extern const ProtobufCMessageDescriptor ctl__set_faulty_req__descriptor;
extern const ProtobufCMessageDescriptor ctl__dev_manage_resp__descriptor;
extern const ProtobufCMessageDescriptor ctl__smd_manage_req__descriptor;
extern const ProtobufCMessageDescriptor ctl__smd_manage_resp__descriptor;
extern const ProtobufCMessageDescriptor ctl__smd_manage_resp__result__descriptor;
extern const ProtobufCMessageDescriptor ctl__smd_manage_resp__rank_resp__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_smd_2eproto__INCLUDED */
