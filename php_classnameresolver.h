#ifndef PHP_CLASSNAMERESOLVER_H
#define PHP_CLASSNAMERESOLVER_H
#define CLASSNAMERESOLVER_VERSION "0.0.1"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "php.h"
#include "zend_API.h"
#include "zend_compile.h"

extern zend_module_entry classnameresolver_module_entry;
#define phpext_classnameresolver_ptr &classnameresolver_module_entry

PHP_METHOD(ClassnameResolver, registerResolver);

PHP_MINIT_FUNCTION(classnameresolver);
PHP_MSHUTDOWN_FUNCTION(classnameresolver);
PHP_MINFO_FUNCTION(classnameresolver);

void (*zend_do_begin_new_object_orig)(znode *new_token, znode *class_type TSRMLS_DC);
void php_classnameresolver_do_begin_new_object(znode *new_token, znode *class_type TSRMLS_DC); 
static zend_class_entry *classnameresolver_ce;

#ifdef ZTS
#define CLASSNAMERESOLVER(v) TSRMG(classnameresolver_globals_id, zend_classnameresolver_globals *, v)
#else
#define CLASSNAMERESOLVER(v) (classnameresolver_globals.v)
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif


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
