#ifndef _CONFIG__H
#define _CONFIG__H 1

#include <yaml.h>
#include "mbus-gw.h"

#define CFG_MAX_RETRIES      10
#define CFG_DEFAULT_TTL      3
#define CFG_DEFAULT_WORKERS  4
#define CFG_DEFAULT_SOCKFILE "/tmp/mbus-gw.sock"

enum err {
    CFG_OK = 0,
    PARSER_SYNTAX,
    UNKNOWN_VALUE,
    MISSED_VALUE,
    INVALID_PARAM,
};

struct cfg {
    int ttl;
    int baud;
    int workers;
    char *sockfile;
    rtu_desc_v rtu_list;
    writeback_v wbq;
    enum err err;
    yaml_parser_t parser;
};

extern struct cfg *cfg_load(const char *fname);
extern void cfg_free(struct cfg *cfg);

#endif /* _CONFIG__H */

