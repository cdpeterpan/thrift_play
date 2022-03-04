/**
 * Autogenerated by Thrift Compiler (0.16.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Serv_H
#define Serv_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "student_types.h"



#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class ServIf {
 public:
  virtual ~ServIf() {}
  virtual void put(const Student& s) = 0;
  virtual void get(Student& _return) = 0;
};

class ServIfFactory {
 public:
  typedef ServIf Handler;

  virtual ~ServIfFactory() {}

  virtual ServIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ServIf* /* handler */) = 0;
  };

class ServIfSingletonFactory : virtual public ServIfFactory {
 public:
  ServIfSingletonFactory(const ::std::shared_ptr<ServIf>& iface) : iface_(iface) {}
  virtual ~ServIfSingletonFactory() {}

  virtual ServIf* getHandler(const ::apache::thrift::TConnectionInfo&) override {
    return iface_.get();
  }
  virtual void releaseHandler(ServIf* /* handler */) override {}

 protected:
  ::std::shared_ptr<ServIf> iface_;
};

class ServNull : virtual public ServIf {
 public:
  virtual ~ServNull() {}
  void put(const Student& /* s */) override {
    return;
  }
  void get(Student& /* _return */) override {
    return;
  }
};

typedef struct _Serv_put_args__isset {
  _Serv_put_args__isset() : s(false) {}
  bool s :1;
} _Serv_put_args__isset;

class Serv_put_args {
 public:

  Serv_put_args(const Serv_put_args&);
  Serv_put_args& operator=(const Serv_put_args&);
  Serv_put_args() noexcept {
  }

  virtual ~Serv_put_args() noexcept;
  Student s;

  _Serv_put_args__isset __isset;

  void __set_s(const Student& val);

  bool operator == (const Serv_put_args & rhs) const
  {
    if (!(s == rhs.s))
      return false;
    return true;
  }
  bool operator != (const Serv_put_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Serv_put_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Serv_put_pargs {
 public:


  virtual ~Serv_put_pargs() noexcept;
  const Student* s;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Serv_put_result {
 public:

  Serv_put_result(const Serv_put_result&) noexcept;
  Serv_put_result& operator=(const Serv_put_result&) noexcept;
  Serv_put_result() noexcept {
  }

  virtual ~Serv_put_result() noexcept;

  bool operator == (const Serv_put_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Serv_put_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Serv_put_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Serv_put_presult {
 public:


  virtual ~Serv_put_presult() noexcept;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class Serv_get_args {
 public:

  Serv_get_args(const Serv_get_args&) noexcept;
  Serv_get_args& operator=(const Serv_get_args&) noexcept;
  Serv_get_args() noexcept {
  }

  virtual ~Serv_get_args() noexcept;

  bool operator == (const Serv_get_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Serv_get_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Serv_get_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Serv_get_pargs {
 public:


  virtual ~Serv_get_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Serv_get_result__isset {
  _Serv_get_result__isset() : success(false) {}
  bool success :1;
} _Serv_get_result__isset;

class Serv_get_result {
 public:

  Serv_get_result(const Serv_get_result&);
  Serv_get_result& operator=(const Serv_get_result&);
  Serv_get_result() noexcept {
  }

  virtual ~Serv_get_result() noexcept;
  Student success;

  _Serv_get_result__isset __isset;

  void __set_success(const Student& val);

  bool operator == (const Serv_get_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Serv_get_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Serv_get_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Serv_get_presult__isset {
  _Serv_get_presult__isset() : success(false) {}
  bool success :1;
} _Serv_get_presult__isset;

class Serv_get_presult {
 public:


  virtual ~Serv_get_presult() noexcept;
  Student* success;

  _Serv_get_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class ServClient : virtual public ServIf {
 public:
  ServClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  ServClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void put(const Student& s) override;
  void send_put(const Student& s);
  void recv_put();
  void get(Student& _return) override;
  void send_get();
  void recv_get(Student& _return);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ServProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<ServIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext) override;
 private:
  typedef  void (ServProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_put(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_get(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ServProcessor(::std::shared_ptr<ServIf> iface) :
    iface_(iface) {
    processMap_["put"] = &ServProcessor::process_put;
    processMap_["get"] = &ServProcessor::process_get;
  }

  virtual ~ServProcessor() {}
};

class ServProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  ServProcessorFactory(const ::std::shared_ptr< ServIfFactory >& handlerFactory) noexcept :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo) override;

 protected:
  ::std::shared_ptr< ServIfFactory > handlerFactory_;
};

class ServMultiface : virtual public ServIf {
 public:
  ServMultiface(std::vector<std::shared_ptr<ServIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ServMultiface() {}
 protected:
  std::vector<std::shared_ptr<ServIf> > ifaces_;
  ServMultiface() {}
  void add(::std::shared_ptr<ServIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void put(const Student& s) override {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->put(s);
    }
    ifaces_[i]->put(s);
  }

  void get(Student& _return) override {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->get(_return);
    }
    ifaces_[i]->get(_return);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class ServConcurrentClient : virtual public ServIf {
 public:
  ServConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  ServConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void put(const Student& s) override;
  int32_t send_put(const Student& s);
  void recv_put(const int32_t seqid);
  void get(Student& _return) override;
  int32_t send_get();
  void recv_get(Student& _return, const int32_t seqid);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif



#endif