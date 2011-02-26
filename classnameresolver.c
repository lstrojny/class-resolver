#include "php_classnameresolver.h"

PHP_MINIT_FUNCTION(classnameresolver)
{
	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(classnameresolver)
{
	return SUCCESS;
}

PHP_MINFO_FUNCTION(classnameresolver)
{
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
	CLASSNAMERESOLVER_EXT_VERSION,
	STANDARD_MODULE_PROPERTIES
};

#if COMPILE_DL_OAUTH
ZEND_GET_MODULE(classnameresolver)
#endif

