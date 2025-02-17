// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: DataExchange.proto

#ifndef PROTOBUF_DataExchange_2eproto__INCLUDED
#define PROTOBUF_DataExchange_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace ttmm {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_DataExchange_2eproto();
void protobuf_AssignDesc_DataExchange_2eproto();
void protobuf_ShutdownFile_DataExchange_2eproto();

class IPCSongInfo;
class IPCSongInfo_IPCMusician;

enum IPCSongInfo_IPCMusician_Tune {
  IPCSongInfo_IPCMusician_Tune_NONE = 0,
  IPCSongInfo_IPCMusician_Tune_LEFT_UP = 1,
  IPCSongInfo_IPCMusician_Tune_MIDDLE_UP = 2,
  IPCSongInfo_IPCMusician_Tune_RIGHT_UP = 3,
  IPCSongInfo_IPCMusician_Tune_LEFT_DOWN = 4,
  IPCSongInfo_IPCMusician_Tune_MIDDLE_DOWN = 5,
  IPCSongInfo_IPCMusician_Tune_RIGHT_DOWN = 6
};
bool IPCSongInfo_IPCMusician_Tune_IsValid(int value);
const IPCSongInfo_IPCMusician_Tune IPCSongInfo_IPCMusician_Tune_Tune_MIN = IPCSongInfo_IPCMusician_Tune_NONE;
const IPCSongInfo_IPCMusician_Tune IPCSongInfo_IPCMusician_Tune_Tune_MAX = IPCSongInfo_IPCMusician_Tune_RIGHT_DOWN;
const int IPCSongInfo_IPCMusician_Tune_Tune_ARRAYSIZE = IPCSongInfo_IPCMusician_Tune_Tune_MAX + 1;

const ::google::protobuf::EnumDescriptor* IPCSongInfo_IPCMusician_Tune_descriptor();
inline const ::std::string& IPCSongInfo_IPCMusician_Tune_Name(IPCSongInfo_IPCMusician_Tune value) {
  return ::google::protobuf::internal::NameOfEnum(
    IPCSongInfo_IPCMusician_Tune_descriptor(), value);
}
inline bool IPCSongInfo_IPCMusician_Tune_Parse(
    const ::std::string& name, IPCSongInfo_IPCMusician_Tune* value) {
  return ::google::protobuf::internal::ParseNamedEnum<IPCSongInfo_IPCMusician_Tune>(
    IPCSongInfo_IPCMusician_Tune_descriptor(), name, value);
}
// ===================================================================

class IPCSongInfo_IPCMusician : public ::google::protobuf::Message {
 public:
  IPCSongInfo_IPCMusician();
  virtual ~IPCSongInfo_IPCMusician();

  IPCSongInfo_IPCMusician(const IPCSongInfo_IPCMusician& from);

  inline IPCSongInfo_IPCMusician& operator=(const IPCSongInfo_IPCMusician& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const IPCSongInfo_IPCMusician& default_instance();

  void Swap(IPCSongInfo_IPCMusician* other);

  // implements Message ----------------------------------------------

  IPCSongInfo_IPCMusician* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const IPCSongInfo_IPCMusician& from);
  void MergeFrom(const IPCSongInfo_IPCMusician& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  typedef IPCSongInfo_IPCMusician_Tune Tune;
  static const Tune NONE = IPCSongInfo_IPCMusician_Tune_NONE;
  static const Tune LEFT_UP = IPCSongInfo_IPCMusician_Tune_LEFT_UP;
  static const Tune MIDDLE_UP = IPCSongInfo_IPCMusician_Tune_MIDDLE_UP;
  static const Tune RIGHT_UP = IPCSongInfo_IPCMusician_Tune_RIGHT_UP;
  static const Tune LEFT_DOWN = IPCSongInfo_IPCMusician_Tune_LEFT_DOWN;
  static const Tune MIDDLE_DOWN = IPCSongInfo_IPCMusician_Tune_MIDDLE_DOWN;
  static const Tune RIGHT_DOWN = IPCSongInfo_IPCMusician_Tune_RIGHT_DOWN;
  static inline bool Tune_IsValid(int value) {
    return IPCSongInfo_IPCMusician_Tune_IsValid(value);
  }
  static const Tune Tune_MIN =
    IPCSongInfo_IPCMusician_Tune_Tune_MIN;
  static const Tune Tune_MAX =
    IPCSongInfo_IPCMusician_Tune_Tune_MAX;
  static const int Tune_ARRAYSIZE =
    IPCSongInfo_IPCMusician_Tune_Tune_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  Tune_descriptor() {
    return IPCSongInfo_IPCMusician_Tune_descriptor();
  }
  static inline const ::std::string& Tune_Name(Tune value) {
    return IPCSongInfo_IPCMusician_Tune_Name(value);
  }
  static inline bool Tune_Parse(const ::std::string& name,
      Tune* value) {
    return IPCSongInfo_IPCMusician_Tune_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // optional sint32 accuracy = 1;
  inline bool has_accuracy() const;
  inline void clear_accuracy();
  static const int kAccuracyFieldNumber = 1;
  inline ::google::protobuf::int32 accuracy() const;
  inline void set_accuracy(::google::protobuf::int32 value);

  // optional sint32 volumeCh1 = 2 [default = -1];
  inline bool has_volumech1() const;
  inline void clear_volumech1();
  static const int kVolumeCh1FieldNumber = 2;
  inline ::google::protobuf::int32 volumech1() const;
  inline void set_volumech1(::google::protobuf::int32 value);

  // optional sint32 volumeCh2 = 3 [default = -1];
  inline bool has_volumech2() const;
  inline void clear_volumech2();
  static const int kVolumeCh2FieldNumber = 3;
  inline ::google::protobuf::int32 volumech2() const;
  inline void set_volumech2(::google::protobuf::int32 value);

  // optional sint32 volumeCh3 = 4 [default = -1];
  inline bool has_volumech3() const;
  inline void clear_volumech3();
  static const int kVolumeCh3FieldNumber = 4;
  inline ::google::protobuf::int32 volumech3() const;
  inline void set_volumech3(::google::protobuf::int32 value);

  // optional .ttmm.IPCSongInfo.IPCMusician.Tune tune = 5;
  inline bool has_tune() const;
  inline void clear_tune();
  static const int kTuneFieldNumber = 5;
  inline ::ttmm::IPCSongInfo_IPCMusician_Tune tune() const;
  inline void set_tune(::ttmm::IPCSongInfo_IPCMusician_Tune value);

  // @@protoc_insertion_point(class_scope:ttmm.IPCSongInfo.IPCMusician)
 private:
  inline void set_has_accuracy();
  inline void clear_has_accuracy();
  inline void set_has_volumech1();
  inline void clear_has_volumech1();
  inline void set_has_volumech2();
  inline void clear_has_volumech2();
  inline void set_has_volumech3();
  inline void clear_has_volumech3();
  inline void set_has_tune();
  inline void clear_has_tune();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::int32 accuracy_;
  ::google::protobuf::int32 volumech1_;
  ::google::protobuf::int32 volumech2_;
  ::google::protobuf::int32 volumech3_;
  int tune_;
  friend void  protobuf_AddDesc_DataExchange_2eproto();
  friend void protobuf_AssignDesc_DataExchange_2eproto();
  friend void protobuf_ShutdownFile_DataExchange_2eproto();

  void InitAsDefaultInstance();
  static IPCSongInfo_IPCMusician* default_instance_;
};
// -------------------------------------------------------------------

class IPCSongInfo : public ::google::protobuf::Message {
 public:
  IPCSongInfo();
  virtual ~IPCSongInfo();

  IPCSongInfo(const IPCSongInfo& from);

  inline IPCSongInfo& operator=(const IPCSongInfo& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const IPCSongInfo& default_instance();

  void Swap(IPCSongInfo* other);

  // implements Message ----------------------------------------------

  IPCSongInfo* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const IPCSongInfo& from);
  void MergeFrom(const IPCSongInfo& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  typedef IPCSongInfo_IPCMusician IPCMusician;

  // accessors -------------------------------------------------------

  // repeated .ttmm.IPCSongInfo.IPCMusician musician = 1;
  inline int musician_size() const;
  inline void clear_musician();
  static const int kMusicianFieldNumber = 1;
  inline const ::ttmm::IPCSongInfo_IPCMusician& musician(int index) const;
  inline ::ttmm::IPCSongInfo_IPCMusician* mutable_musician(int index);
  inline ::ttmm::IPCSongInfo_IPCMusician* add_musician();
  inline const ::google::protobuf::RepeatedPtrField< ::ttmm::IPCSongInfo_IPCMusician >&
      musician() const;
  inline ::google::protobuf::RepeatedPtrField< ::ttmm::IPCSongInfo_IPCMusician >*
      mutable_musician();

  // @@protoc_insertion_point(class_scope:ttmm.IPCSongInfo)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::ttmm::IPCSongInfo_IPCMusician > musician_;
  friend void  protobuf_AddDesc_DataExchange_2eproto();
  friend void protobuf_AssignDesc_DataExchange_2eproto();
  friend void protobuf_ShutdownFile_DataExchange_2eproto();

  void InitAsDefaultInstance();
  static IPCSongInfo* default_instance_;
};
// ===================================================================


// ===================================================================

// IPCSongInfo_IPCMusician

// optional sint32 accuracy = 1;
inline bool IPCSongInfo_IPCMusician::has_accuracy() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void IPCSongInfo_IPCMusician::set_has_accuracy() {
  _has_bits_[0] |= 0x00000001u;
}
inline void IPCSongInfo_IPCMusician::clear_has_accuracy() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void IPCSongInfo_IPCMusician::clear_accuracy() {
  accuracy_ = 0;
  clear_has_accuracy();
}
inline ::google::protobuf::int32 IPCSongInfo_IPCMusician::accuracy() const {
  // @@protoc_insertion_point(field_get:ttmm.IPCSongInfo.IPCMusician.accuracy)
  return accuracy_;
}
inline void IPCSongInfo_IPCMusician::set_accuracy(::google::protobuf::int32 value) {
  set_has_accuracy();
  accuracy_ = value;
  // @@protoc_insertion_point(field_set:ttmm.IPCSongInfo.IPCMusician.accuracy)
}

// optional sint32 volumeCh1 = 2 [default = -1];
inline bool IPCSongInfo_IPCMusician::has_volumech1() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void IPCSongInfo_IPCMusician::set_has_volumech1() {
  _has_bits_[0] |= 0x00000002u;
}
inline void IPCSongInfo_IPCMusician::clear_has_volumech1() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void IPCSongInfo_IPCMusician::clear_volumech1() {
  volumech1_ = -1;
  clear_has_volumech1();
}
inline ::google::protobuf::int32 IPCSongInfo_IPCMusician::volumech1() const {
  // @@protoc_insertion_point(field_get:ttmm.IPCSongInfo.IPCMusician.volumeCh1)
  return volumech1_;
}
inline void IPCSongInfo_IPCMusician::set_volumech1(::google::protobuf::int32 value) {
  set_has_volumech1();
  volumech1_ = value;
  // @@protoc_insertion_point(field_set:ttmm.IPCSongInfo.IPCMusician.volumeCh1)
}

// optional sint32 volumeCh2 = 3 [default = -1];
inline bool IPCSongInfo_IPCMusician::has_volumech2() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void IPCSongInfo_IPCMusician::set_has_volumech2() {
  _has_bits_[0] |= 0x00000004u;
}
inline void IPCSongInfo_IPCMusician::clear_has_volumech2() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void IPCSongInfo_IPCMusician::clear_volumech2() {
  volumech2_ = -1;
  clear_has_volumech2();
}
inline ::google::protobuf::int32 IPCSongInfo_IPCMusician::volumech2() const {
  // @@protoc_insertion_point(field_get:ttmm.IPCSongInfo.IPCMusician.volumeCh2)
  return volumech2_;
}
inline void IPCSongInfo_IPCMusician::set_volumech2(::google::protobuf::int32 value) {
  set_has_volumech2();
  volumech2_ = value;
  // @@protoc_insertion_point(field_set:ttmm.IPCSongInfo.IPCMusician.volumeCh2)
}

// optional sint32 volumeCh3 = 4 [default = -1];
inline bool IPCSongInfo_IPCMusician::has_volumech3() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void IPCSongInfo_IPCMusician::set_has_volumech3() {
  _has_bits_[0] |= 0x00000008u;
}
inline void IPCSongInfo_IPCMusician::clear_has_volumech3() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void IPCSongInfo_IPCMusician::clear_volumech3() {
  volumech3_ = -1;
  clear_has_volumech3();
}
inline ::google::protobuf::int32 IPCSongInfo_IPCMusician::volumech3() const {
  // @@protoc_insertion_point(field_get:ttmm.IPCSongInfo.IPCMusician.volumeCh3)
  return volumech3_;
}
inline void IPCSongInfo_IPCMusician::set_volumech3(::google::protobuf::int32 value) {
  set_has_volumech3();
  volumech3_ = value;
  // @@protoc_insertion_point(field_set:ttmm.IPCSongInfo.IPCMusician.volumeCh3)
}

// optional .ttmm.IPCSongInfo.IPCMusician.Tune tune = 5;
inline bool IPCSongInfo_IPCMusician::has_tune() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void IPCSongInfo_IPCMusician::set_has_tune() {
  _has_bits_[0] |= 0x00000010u;
}
inline void IPCSongInfo_IPCMusician::clear_has_tune() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void IPCSongInfo_IPCMusician::clear_tune() {
  tune_ = 0;
  clear_has_tune();
}
inline ::ttmm::IPCSongInfo_IPCMusician_Tune IPCSongInfo_IPCMusician::tune() const {
  // @@protoc_insertion_point(field_get:ttmm.IPCSongInfo.IPCMusician.tune)
  return static_cast< ::ttmm::IPCSongInfo_IPCMusician_Tune >(tune_);
}
inline void IPCSongInfo_IPCMusician::set_tune(::ttmm::IPCSongInfo_IPCMusician_Tune value) {
  assert(::ttmm::IPCSongInfo_IPCMusician_Tune_IsValid(value));
  set_has_tune();
  tune_ = value;
  // @@protoc_insertion_point(field_set:ttmm.IPCSongInfo.IPCMusician.tune)
}

// -------------------------------------------------------------------

// IPCSongInfo

// repeated .ttmm.IPCSongInfo.IPCMusician musician = 1;
inline int IPCSongInfo::musician_size() const {
  return musician_.size();
}
inline void IPCSongInfo::clear_musician() {
  musician_.Clear();
}
inline const ::ttmm::IPCSongInfo_IPCMusician& IPCSongInfo::musician(int index) const {
  // @@protoc_insertion_point(field_get:ttmm.IPCSongInfo.musician)
  return musician_.Get(index);
}
inline ::ttmm::IPCSongInfo_IPCMusician* IPCSongInfo::mutable_musician(int index) {
  // @@protoc_insertion_point(field_mutable:ttmm.IPCSongInfo.musician)
  return musician_.Mutable(index);
}
inline ::ttmm::IPCSongInfo_IPCMusician* IPCSongInfo::add_musician() {
  // @@protoc_insertion_point(field_add:ttmm.IPCSongInfo.musician)
  return musician_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::ttmm::IPCSongInfo_IPCMusician >&
IPCSongInfo::musician() const {
  // @@protoc_insertion_point(field_list:ttmm.IPCSongInfo.musician)
  return musician_;
}
inline ::google::protobuf::RepeatedPtrField< ::ttmm::IPCSongInfo_IPCMusician >*
IPCSongInfo::mutable_musician() {
  // @@protoc_insertion_point(field_mutable_list:ttmm.IPCSongInfo.musician)
  return &musician_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace ttmm

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::ttmm::IPCSongInfo_IPCMusician_Tune> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::ttmm::IPCSongInfo_IPCMusician_Tune>() {
  return ::ttmm::IPCSongInfo_IPCMusician_Tune_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_DataExchange_2eproto__INCLUDED
