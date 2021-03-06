#ifndef __HUSTSTORE_BINLOG_TASK_H_
#define __HUSTSTORE_BINLOG_TASK_H_

#include <string>
#include <stdint.h>

class husthttp_t;
class queue_t;

typedef void ( *callback_func_t ) ( void * param );

class task_t
{
    
public:
    
    explicit task_t (
                      const char * host,
                      size_t host_len,
                      callback_func_t callback_func,
                      void * param,
                      const std::string & auth,
                      size_t alive_time
                      );
    ~task_t ( );

    bool make_task (
                     const char * host,
                     size_t host_len,
                     const char * table,
                     size_t table_len,
                     const char * key,
                     size_t key_len,
                     const char * value,
                     size_t value_len,
                     uint32_t ver,
                     uint32_t ttl,
                     uint8_t cmd_type
                     );

    bool run (
               husthttp_t * client
               );
    
private:
    
    bool url_encode_all ( const char *, int, char *, int * );
    
    bool is_success ( int * http_code );

    bool inner_handle ( husthttp_t * );

    bool is_overtime ( );

    std::string _host;
    std::string _url;
    std::string _method;
    std::string _path;
    std::string _query_string;
    std::string _value;

    std::string _head;
    std::string _body;

    callback_func_t _callback_func;
    void * _cb_param;

    int _http_code;

    int64_t _alive_time;
    int64_t _timestamp;
};

#endif