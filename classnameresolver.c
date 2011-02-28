#include "php_classnameresolver.h"

#include <stdio.h>
#include "php.h"
#include "zend_API.h"
#include "standard/info.h"
#include "zend_compile.h"

ZEND_BEGIN_ARG_INFO(arginfo_ClassnameResolver_registerResolver, 0)
	ZEND_ARG_INFO(0, resolver)
ZEND_END_ARG_INFO()


static zend_function_entry php_classnameresolver_methods[] = {
	PHP_ME(ClassnameResolver,registerResolver, arginfo_ClassnameResolver_registerResolver, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
};


void php_classnameresolver_do_begin_new_object(znode *new_token, znode *class_type TSRMLS_DC) 
{
	printf("INTERCEPTED\n");
	return zend_do_begin_new_object_orig(new_token, class_type);
}


PHP_MINIT_FUNCTION(classnameresolver)
{
	zend_class_entry classnameresolver_class_entry;

	INIT_CLASS_ENTRY(classnameresolver_class_entry, "ClassnameResolver", php_classnameresolver_methods);
	classnameresolver_ce = zend_register_internal_class(&classnameresolver_class_entry TSRMLS_CC);

	zend_do_begin_new_object_orig = zend_do_begin_new_object;
	zend_do_begin_new_object_t = php_classnameresolver_do_begin_new_object;

	return SUCCESS;
}


PHP_MSHUTDOWN_FUNCTION(classnameresolver)
{
	zend_do_begin_new_object_t = zend_do_begin_new_object_orig;

	return SUCCESS;
}


PHP_MINFO_FUNCTION(classnameresolver)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "Classname Resolver support", "enabled");
	php_info_print_table_row(2, "version", CLASSNAMERESOLVER_VERSION);
	php_info_print_table_end();
}

zend_module_entry classnameresolver_module_entry = {
	STANDARD_MODULE_HEADER,
	"Classname Resolver",
	NULL,
	PHP_MINIT(classnameresolver),
	PHP_MSHUTDOWN(classnameresolver),
	NULL,
	NULL,
	PHP_MINFO(classnameresolver),
	CLASSNAMERESOLVER_VERSION,
	STANDARD_MODULE_PROPERTIES
};


#if COMPILE_DL_CLASSNAMERESOLVER
ZEND_GET_MODULE(classnameresolver)
#endif

PHP_METHOD(ClassnameResolver, registerResolver)
{
	RETURN_TRUE;
}
