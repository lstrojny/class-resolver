#include "php_classresolver.h"

#include <stdio.h>
#include "php.h"
#include "zend_API.h"
#include "standard/info.h"
#include "zend_compile.h"
#include "zend_hash.h"

ZEND_DECLARE_MODULE_GLOBALS(classresolver)

ZEND_API zend_object_value php_classresolver_create_object(zend_object **object, zend_class_entry *class_type TSRMLS_DC)
{
    printf("php_classresolver_create_object()\n");
    return zend_objects_new(object, class_type);
}

ZEND_API int php_classresolver_register_create_object_handler(zend_class_entry **ce)
{
    printf("Registering %s\n", (*ce)->name);

    if ((*ce)->create_object != NULL) {
        printf("ADD\n");
        zend_hash_add(
                CLASSRESOLVER_G(create_object_handlers),
                (*ce)->name,
                (*ce)->name_length + 1,
                (void *)((*ce)->create_object),
                sizeof(void *),
                NULL
                TSRMLS_CC
        );
        printf("AFTER ADD\n");
    }
    //(*ce)->create_object = php_classresolver_create_object;

    return 0;
}

PHP_MINIT_FUNCTION(classresolver)
{
        ZEND_INIT_MODULE_GLOBALS(classresolver, php_classresolver_init_globals, NULL);

        zend_hash_apply(CG(class_table), (apply_func_arg_t) php_classresolver_register_create_object_handler TSRMLS_CC);

	return SUCCESS;
}

static void php_classresolver_init_globals(zend_classresolver_globals *globals)
{
    globals->create_object_handlers = (HashTable *)emalloc(sizeof(HashTable));
}

PHP_MSHUTDOWN_FUNCTION(classresolver)
{
        efree(CLASSRESOLVER_G(create_object_handlers));

	return SUCCESS;
}


PHP_MINFO_FUNCTION(classresolver)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "Classname Resolver support", "enabled");
	php_info_print_table_row(2, "version", CLASSRESOLVER_VERSION);
	php_info_print_table_end();
}

zend_module_entry classresolver_module_entry = {
	STANDARD_MODULE_HEADER,
	"Classname Resolver",
	NULL,
	PHP_MINIT(classresolver),
	PHP_MSHUTDOWN(classresolver),
	NULL,
	NULL,
	PHP_MINFO(classresolver),
	CLASSRESOLVER_VERSION,
	STANDARD_MODULE_PROPERTIES
};


#if COMPILE_DL_CLASSRESOLVER
ZEND_GET_MODULE(classresolver)
#endif

PHP_METHOD(ClassnameResolver, registerResolver)
{
	RETURN_TRUE;
}
