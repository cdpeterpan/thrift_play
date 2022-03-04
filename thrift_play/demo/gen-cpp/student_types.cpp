/**
 * Autogenerated by Thrift Compiler (0.16.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "student_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>




Student::~Student() noexcept {
}


void Student::__set_sno(const int32_t val) {
  this->sno = val;
}

void Student::__set_sname(const std::string& val) {
  this->sname = val;
}

void Student::__set_ssex(const bool val) {
  this->ssex = val;
}

void Student::__set_sage(const int16_t val) {
  this->sage = val;
}
std::ostream& operator<<(std::ostream& out, const Student& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t Student::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->sno);
          this->__isset.sno = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->sname);
          this->__isset.sname = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->ssex);
          this->__isset.ssex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->sage);
          this->__isset.sage = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Student::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Student");

  xfer += oprot->writeFieldBegin("sno", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->sno);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("sname", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->sname);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("ssex", ::apache::thrift::protocol::T_BOOL, 3);
  xfer += oprot->writeBool(this->ssex);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("sage", ::apache::thrift::protocol::T_I16, 4);
  xfer += oprot->writeI16(this->sage);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Student &a, Student &b) {
  using ::std::swap;
  swap(a.sno, b.sno);
  swap(a.sname, b.sname);
  swap(a.ssex, b.ssex);
  swap(a.sage, b.sage);
  swap(a.__isset, b.__isset);
}

Student::Student(const Student& other0) {
  sno = other0.sno;
  sname = other0.sname;
  ssex = other0.ssex;
  sage = other0.sage;
  __isset = other0.__isset;
}
Student& Student::operator=(const Student& other1) {
  sno = other1.sno;
  sname = other1.sname;
  ssex = other1.ssex;
  sage = other1.sage;
  __isset = other1.__isset;
  return *this;
}
void Student::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "Student(";
  out << "sno=" << to_string(sno);
  out << ", " << "sname=" << to_string(sname);
  out << ", " << "ssex=" << to_string(ssex);
  out << ", " << "sage=" << to_string(sage);
  out << ")";
}


