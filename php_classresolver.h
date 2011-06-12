#ifndef PHP_CLASSRESOLVER_H
#define PHP_CLASSRESOLVER_H
#define CLASSRESOLVER_VERSION "0.0.1"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "php.h"
#include "zend_objects.h"

extern zend_module_entry classresolver_module_entry;
#define phpext_classresolver_ptr &classresolver_module_entry

PHP_MINIT_FUNCTION(classresolver);
PHP_MSHUTDOWN_FUNCTION(classresolver);
PHP_MINFO_FUNCTION(classresolver);

ZEND_API zend_object_value php_classresolver_create_object(zend_object **object, zend_class_entry *class_type TSRMLS_DC);
ZEND_API int php_classresolver_register_create_object_handler(zend_class_entry **ce);
static void php_classresolver_init_globals();


ZEND_BEGIN_MODULE_GLOBALS(classresolver)
        HashTable *create_object_handlers;
        zend_function *class_resolver;
        zend_function *configurator;
ZEND_END_MODULE_GLOBALS(classresolver)


#ifdef ZTS
#define CLASSRESOLVER_G(v) TSRMG(classresolver_globals_id, zend_classresolver_globals *, v)
#else
#define CLASSRESOLVER_G(v) (classresolver_globals.v)
#endif
ZEND_EXTERN_MODULE_GLOBALS(classresolver)

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
