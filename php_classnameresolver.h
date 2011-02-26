#ifndef PHP_CLASSNAMERESOLVER_H
#define PHP_CLASSNAMERESOLVER_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

extern zend_module_entry classnameresolver_module_entry;

#define phpext_oauth_ptr &classnameresolver_module_entry

PHP_MINIT_FUNCTION(classnameresolver);
PHP_MSHUTDOWN_FUNCTION(classnameresolver);
PHP_MINFO_FUNCTION(classnameresolver);


#ifdef ZTS
#define CLASSNAMERESOLVER(v) TSRMG(classnameresolver_globals_id, zend_classnameresolver_globals *, v)
#else
#define CLASSNAMERESOLVER(v) (classnameresolver_globals.v)
#endif

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

#define CLASSNAMERESOLVER_EXT_VERSION "0.0.1"

#endif

/**
 * Local Variables:
 * c-basic-offset: 4
 * tab-width: 4
 * indent-tabs-mode: t
 * End:
 * vim600: fdm=marker
 * vim: noet sw=4 ts=4 noexpandtab
 */
