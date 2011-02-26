/*
   +----------------------------------------------------------------------+
   | unknown license:                                                      |
   +----------------------------------------------------------------------+
   +----------------------------------------------------------------------+
*/

/* $ Id: $ */ 

#include "php_classnameresolver.h"

#if HAVE_CLASSNAMERESOLVER

/* {{{ classnameresolver_functions[] */
function_entry classnameresolver_functions[] = {
	{ NULL, NULL, NULL }
};
/* }}} */


/* {{{ classnameresolver_module_entry
 */
zend_module_entry classnameresolver_module_entry = {
	STANDARD_MODULE_HEADER,
	"classnameresolver",
	classnameresolver_functions,
	PHP_MINIT(classnameresolver),     /* Replace with NULL if there is nothing to do at php startup   */ 
	PHP_MSHUTDOWN(classnameresolver), /* Replace with NULL if there is nothing to do at php shutdown  */
	PHP_RINIT(classnameresolver),     /* Replace with NULL if there is nothing to do at request start */
	PHP_RSHUTDOWN(classnameresolver), /* Replace with NULL if there is nothing to do at request end   */
	PHP_MINFO(classnameresolver),
	PHP_CLASSNAMERESOLVER_VERSION, 
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_CLASSNAMERESOLVER
ZEND_GET_MODULE(classnameresolver)
#endif


/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(classnameresolver)
{

	/* add your stuff here */

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_MSHUTDOWN_FUNCTION */
PHP_MSHUTDOWN_FUNCTION(classnameresolver)
{

	/* add your stuff here */

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(classnameresolver)
{
	/* add your stuff here */

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_RSHUTDOWN_FUNCTION */
PHP_RSHUTDOWN_FUNCTION(classnameresolver)
{
	/* add your stuff here */

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(classnameresolver)
{
	php_printf("The unknown extension\n");
	php_info_print_table_start();
	php_info_print_table_row(2, "Version",PHP_CLASSNAMERESOLVER_VERSION " (devel)");
	php_info_print_table_row(2, "Released", "2011-02-26");
	php_info_print_table_row(2, "CVS Revision", "$Id: $");
	php_info_print_table_end();
	/* add your stuff here */

}
/* }}} */

#endif /* HAVE_CLASSNAMERESOLVER */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
