// Code generated by protoc-gen-go. DO NOT EDIT.
// source: acl.proto

package mgmt

import (
	fmt "fmt"
	proto "github.com/golang/protobuf/proto"
	math "math"
)

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// This is a compile-time assertion to ensure that this generated file
// is compatible with the proto package it is being compiled against.
// A compilation error at this line likely means your copy of the
// proto package needs to be updated.
const _ = proto.ProtoPackageIsVersion3 // please upgrade the proto package

// Response to ACL-related requests includes the command status and current ACL
type ACLResp struct {
	Status               int32    `protobuf:"varint,1,opt,name=status,proto3" json:"status,omitempty"`
	ACL                  []string `protobuf:"bytes,2,rep,name=ACL,proto3" json:"ACL,omitempty"`
	OwnerUser            string   `protobuf:"bytes,3,opt,name=ownerUser,proto3" json:"ownerUser,omitempty"`
	OwnerGroup           string   `protobuf:"bytes,4,opt,name=ownerGroup,proto3" json:"ownerGroup,omitempty"`
	XXX_NoUnkeyedLiteral struct{} `json:"-"`
	XXX_unrecognized     []byte   `json:"-"`
	XXX_sizecache        int32    `json:"-"`
}

func (m *ACLResp) Reset()         { *m = ACLResp{} }
func (m *ACLResp) String() string { return proto.CompactTextString(m) }
func (*ACLResp) ProtoMessage()    {}
func (*ACLResp) Descriptor() ([]byte, []int) {
	return fileDescriptor_a452f070aeef01eb, []int{0}
}

func (m *ACLResp) XXX_Unmarshal(b []byte) error {
	return xxx_messageInfo_ACLResp.Unmarshal(m, b)
}
func (m *ACLResp) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	return xxx_messageInfo_ACLResp.Marshal(b, m, deterministic)
}
func (m *ACLResp) XXX_Merge(src proto.Message) {
	xxx_messageInfo_ACLResp.Merge(m, src)
}
func (m *ACLResp) XXX_Size() int {
	return xxx_messageInfo_ACLResp.Size(m)
}
func (m *ACLResp) XXX_DiscardUnknown() {
	xxx_messageInfo_ACLResp.DiscardUnknown(m)
}

var xxx_messageInfo_ACLResp proto.InternalMessageInfo

func (m *ACLResp) GetStatus() int32 {
	if m != nil {
		return m.Status
	}
	return 0
}

func (m *ACLResp) GetACL() []string {
	if m != nil {
		return m.ACL
	}
	return nil
}

func (m *ACLResp) GetOwnerUser() string {
	if m != nil {
		return m.OwnerUser
	}
	return ""
}

func (m *ACLResp) GetOwnerGroup() string {
	if m != nil {
		return m.OwnerGroup
	}
	return ""
}

// Request to fetch an ACL
type GetACLReq struct {
	Sys                  string   `protobuf:"bytes,1,opt,name=sys,proto3" json:"sys,omitempty"`
	Uuid                 string   `protobuf:"bytes,2,opt,name=uuid,proto3" json:"uuid,omitempty"`
	SvcRanks             []uint32 `protobuf:"varint,3,rep,packed,name=svc_ranks,json=svcRanks,proto3" json:"svc_ranks,omitempty"`
	XXX_NoUnkeyedLiteral struct{} `json:"-"`
	XXX_unrecognized     []byte   `json:"-"`
	XXX_sizecache        int32    `json:"-"`
}

func (m *GetACLReq) Reset()         { *m = GetACLReq{} }
func (m *GetACLReq) String() string { return proto.CompactTextString(m) }
func (*GetACLReq) ProtoMessage()    {}
func (*GetACLReq) Descriptor() ([]byte, []int) {
	return fileDescriptor_a452f070aeef01eb, []int{1}
}

func (m *GetACLReq) XXX_Unmarshal(b []byte) error {
	return xxx_messageInfo_GetACLReq.Unmarshal(m, b)
}
func (m *GetACLReq) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	return xxx_messageInfo_GetACLReq.Marshal(b, m, deterministic)
}
func (m *GetACLReq) XXX_Merge(src proto.Message) {
	xxx_messageInfo_GetACLReq.Merge(m, src)
}
func (m *GetACLReq) XXX_Size() int {
	return xxx_messageInfo_GetACLReq.Size(m)
}
func (m *GetACLReq) XXX_DiscardUnknown() {
	xxx_messageInfo_GetACLReq.DiscardUnknown(m)
}

var xxx_messageInfo_GetACLReq proto.InternalMessageInfo

func (m *GetACLReq) GetSys() string {
	if m != nil {
		return m.Sys
	}
	return ""
}

func (m *GetACLReq) GetUuid() string {
	if m != nil {
		return m.Uuid
	}
	return ""
}

func (m *GetACLReq) GetSvcRanks() []uint32 {
	if m != nil {
		return m.SvcRanks
	}
	return nil
}

// Request to modify an ACL
// Results depend on the specific modification command.
type ModifyACLReq struct {
	Sys                  string   `protobuf:"bytes,1,opt,name=sys,proto3" json:"sys,omitempty"`
	Uuid                 string   `protobuf:"bytes,2,opt,name=uuid,proto3" json:"uuid,omitempty"`
	ACL                  []string `protobuf:"bytes,3,rep,name=ACL,proto3" json:"ACL,omitempty"`
	SvcRanks             []uint32 `protobuf:"varint,4,rep,packed,name=svc_ranks,json=svcRanks,proto3" json:"svc_ranks,omitempty"`
	XXX_NoUnkeyedLiteral struct{} `json:"-"`
	XXX_unrecognized     []byte   `json:"-"`
	XXX_sizecache        int32    `json:"-"`
}

func (m *ModifyACLReq) Reset()         { *m = ModifyACLReq{} }
func (m *ModifyACLReq) String() string { return proto.CompactTextString(m) }
func (*ModifyACLReq) ProtoMessage()    {}
func (*ModifyACLReq) Descriptor() ([]byte, []int) {
	return fileDescriptor_a452f070aeef01eb, []int{2}
}

func (m *ModifyACLReq) XXX_Unmarshal(b []byte) error {
	return xxx_messageInfo_ModifyACLReq.Unmarshal(m, b)
}
func (m *ModifyACLReq) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	return xxx_messageInfo_ModifyACLReq.Marshal(b, m, deterministic)
}
func (m *ModifyACLReq) XXX_Merge(src proto.Message) {
	xxx_messageInfo_ModifyACLReq.Merge(m, src)
}
func (m *ModifyACLReq) XXX_Size() int {
	return xxx_messageInfo_ModifyACLReq.Size(m)
}
func (m *ModifyACLReq) XXX_DiscardUnknown() {
	xxx_messageInfo_ModifyACLReq.DiscardUnknown(m)
}

var xxx_messageInfo_ModifyACLReq proto.InternalMessageInfo

func (m *ModifyACLReq) GetSys() string {
	if m != nil {
		return m.Sys
	}
	return ""
}

func (m *ModifyACLReq) GetUuid() string {
	if m != nil {
		return m.Uuid
	}
	return ""
}

func (m *ModifyACLReq) GetACL() []string {
	if m != nil {
		return m.ACL
	}
	return nil
}

func (m *ModifyACLReq) GetSvcRanks() []uint32 {
	if m != nil {
		return m.SvcRanks
	}
	return nil
}

// Delete a principal's entry from the ACL
type DeleteACLReq struct {
	Sys                  string   `protobuf:"bytes,1,opt,name=sys,proto3" json:"sys,omitempty"`
	Uuid                 string   `protobuf:"bytes,2,opt,name=uuid,proto3" json:"uuid,omitempty"`
	Principal            string   `protobuf:"bytes,3,opt,name=principal,proto3" json:"principal,omitempty"`
	SvcRanks             []uint32 `protobuf:"varint,4,rep,packed,name=svc_ranks,json=svcRanks,proto3" json:"svc_ranks,omitempty"`
	XXX_NoUnkeyedLiteral struct{} `json:"-"`
	XXX_unrecognized     []byte   `json:"-"`
	XXX_sizecache        int32    `json:"-"`
}

func (m *DeleteACLReq) Reset()         { *m = DeleteACLReq{} }
func (m *DeleteACLReq) String() string { return proto.CompactTextString(m) }
func (*DeleteACLReq) ProtoMessage()    {}
func (*DeleteACLReq) Descriptor() ([]byte, []int) {
	return fileDescriptor_a452f070aeef01eb, []int{3}
}

func (m *DeleteACLReq) XXX_Unmarshal(b []byte) error {
	return xxx_messageInfo_DeleteACLReq.Unmarshal(m, b)
}
func (m *DeleteACLReq) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	return xxx_messageInfo_DeleteACLReq.Marshal(b, m, deterministic)
}
func (m *DeleteACLReq) XXX_Merge(src proto.Message) {
	xxx_messageInfo_DeleteACLReq.Merge(m, src)
}
func (m *DeleteACLReq) XXX_Size() int {
	return xxx_messageInfo_DeleteACLReq.Size(m)
}
func (m *DeleteACLReq) XXX_DiscardUnknown() {
	xxx_messageInfo_DeleteACLReq.DiscardUnknown(m)
}

var xxx_messageInfo_DeleteACLReq proto.InternalMessageInfo

func (m *DeleteACLReq) GetSys() string {
	if m != nil {
		return m.Sys
	}
	return ""
}

func (m *DeleteACLReq) GetUuid() string {
	if m != nil {
		return m.Uuid
	}
	return ""
}

func (m *DeleteACLReq) GetPrincipal() string {
	if m != nil {
		return m.Principal
	}
	return ""
}

func (m *DeleteACLReq) GetSvcRanks() []uint32 {
	if m != nil {
		return m.SvcRanks
	}
	return nil
}

func init() {
	proto.RegisterType((*ACLResp)(nil), "mgmt.ACLResp")
	proto.RegisterType((*GetACLReq)(nil), "mgmt.GetACLReq")
	proto.RegisterType((*ModifyACLReq)(nil), "mgmt.ModifyACLReq")
	proto.RegisterType((*DeleteACLReq)(nil), "mgmt.DeleteACLReq")
}

func init() {
	proto.RegisterFile("acl.proto", fileDescriptor_a452f070aeef01eb)
}

var fileDescriptor_a452f070aeef01eb = []byte{
	// 240 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x94, 0x91, 0xc1, 0x4a, 0x03, 0x31,
	0x10, 0x86, 0xd9, 0x66, 0xad, 0xce, 0x50, 0x41, 0xe6, 0x20, 0x01, 0x8b, 0x2c, 0x7b, 0xda, 0x93,
	0x17, 0x9f, 0xa0, 0x54, 0xe8, 0xa5, 0x7a, 0x08, 0x78, 0x96, 0x35, 0x8d, 0xb2, 0xb8, 0xdd, 0xa4,
	0x99, 0xa4, 0xd2, 0xb7, 0x97, 0xc4, 0x6a, 0xd5, 0x83, 0xd0, 0xdb, 0xff, 0x7f, 0x81, 0xf9, 0x98,
	0x0c, 0x42, 0xab, 0xfb, 0x1b, 0xe7, 0x6d, 0xb0, 0x54, 0xae, 0x5f, 0xd7, 0xa1, 0xde, 0xe0, 0xe9,
	0x6c, 0xbe, 0x54, 0x86, 0x1d, 0x5d, 0xe2, 0x98, 0x43, 0x1b, 0x22, 0xcb, 0xa2, 0x2a, 0x9a, 0x13,
	0xb5, 0x6f, 0x74, 0x81, 0x62, 0x36, 0x5f, 0xca, 0x51, 0x25, 0x1a, 0x50, 0x29, 0xd2, 0x14, 0xc1,
	0xbe, 0x0f, 0xc6, 0x3f, 0xb2, 0xf1, 0x52, 0x54, 0x45, 0x03, 0xea, 0x00, 0xe8, 0x1a, 0x31, 0x97,
	0x85, 0xb7, 0xd1, 0xc9, 0x32, 0x3f, 0xff, 0x20, 0xf5, 0x03, 0xc2, 0xc2, 0x84, 0x6c, 0xdd, 0xa4,
	0xe1, 0xbc, 0xfb, 0x34, 0x82, 0x4a, 0x91, 0x08, 0xcb, 0x18, 0xbb, 0x95, 0x1c, 0x65, 0x94, 0x33,
	0x5d, 0x21, 0xf0, 0x56, 0x3f, 0xf9, 0x76, 0x78, 0x63, 0x29, 0x2a, 0xd1, 0x9c, 0xab, 0x33, 0xde,
	0x6a, 0x95, 0x7a, 0xad, 0x71, 0x72, 0x6f, 0x57, 0xdd, 0xcb, 0xee, 0xa8, 0x91, 0xfb, 0xad, 0xc4,
	0x61, 0xab, 0x5f, 0x92, 0xf2, 0x8f, 0xc4, 0xe2, 0xe4, 0xce, 0xf4, 0x26, 0x98, 0xa3, 0x24, 0x53,
	0x04, 0xe7, 0xbb, 0x41, 0x77, 0xae, 0xed, 0xbf, 0x3e, 0xea, 0x1b, 0xfc, 0x2b, 0x7c, 0x1e, 0xe7,
	0x2b, 0xdd, 0x7e, 0x04, 0x00, 0x00, 0xff, 0xff, 0xca, 0xe6, 0xc1, 0x9a, 0xb2, 0x01, 0x00, 0x00,
}
