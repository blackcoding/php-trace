/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2018 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_say_ke.h"
#include "stdio.h"

/* If you declare any globals in php_say_ke.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(say_ke)
*/

/* True global resources - no need for thread safety here */
static int le_say_ke;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("say_ke.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_say_ke_globals, say_ke_globals)
    STD_PHP_INI_ENTRY("say_ke.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_say_ke_globals, say_ke_globals)
PHP_INI_END()
*/
/* }}} */

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_say_ke_compiled(string arg)
   Return a string to confirm that the module is compiled in */
ZEND_BEGIN_ARG_INFO(arginfo_say_ke, 0)
ZEND_END_ARG_INFO()

/*
PHP_FUNCTION(confirm_say_ke_compiled)
{
	char *arg = NULL;
	size_t arg_len, len;
	zend_string *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	strg = strpprintf(0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "say_ke", arg);

	RETURN_STR(strg);
	php_printf("confirm say ke compiled\n");
	RETURN_TRUE;
}*/

PHP_FUNCTION(say_ke)
{
	char *name;
	int name_len;

	int argNum = ZEND_NUM_ARGS();
	if(argNum){
		php_printf("get params num failed\n");
	}

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &name, &name_len) == FAILURE) {
		RETURN_NULL();
	}

	/*
	if(zend_parse_parameters(1,"s",&name, &name_len ) == FAILURE){
		RETURN_NULL();
	}
	*/
	php_printf("Hello : ");
	if(name){
		php_printf("name is null\n");
	}else{
		PHPWRITE(name, name_len);
	}
	RETURN_TRUE;
}


/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/


/* {{{ php_say_ke_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_say_ke_init_globals(zend_say_ke_globals *say_ke_globals)
{
	say_ke_globals->global_value = 0;
	say_ke_globals->global_string = NULL;

	RETURN_TRUE;}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(say_ke)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	php_printf("SAY_KE STEP : --> PHP_MINIT_FUNCTION\n");
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(say_ke)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	php_printf("SAY_KE STEP : --> PHP_MSHUTDOWN_FUNCTION\n");
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(say_ke)
{
#if defined(COMPILE_DL_SAY_KE) && defined(ZTS)
	php_printf("SAY_KE STEP : --> PHP_RINIT_FUNCTION, defined COMPILE_DL_SAY_KE and ZTS\n");
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	php_printf("SAY_KE STEP : --> PHP_RINIT_FUNCTION\n");
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(say_ke)
{
	php_printf("SAY_KE STEP : --> PHP_RSHUTDOWN_FUNCTION\n");
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(say_ke)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "say_ke support", "enabled");
	php_info_print_table_row(2, "author", "anding");
	php_info_print_table_row(2, "date", "2019-05-24");
	php_info_print_table_row(2, "version", PHP_SAY_KE_VERSION);
	php_info_print_table_end();
	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ say_ke_functions[]
 *
 * Every user visible function must have an entry in say_ke_functions[].
 */
const zend_function_entry say_ke_functions[] = {
//	PHP_FE(confirm_say_ke_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE(say_ke, arginfo_say_ke)
	PHP_FE_END	/* Must be the last line in say_ke_functions[] */
};
/* }}} */

/* {{{ say_ke_module_entry
 */
zend_module_entry say_ke_module_entry = {
	STANDARD_MODULE_HEADER,
	"say_ke",
	say_ke_functions,
	PHP_MINIT(say_ke),
	PHP_MSHUTDOWN(say_ke),
	PHP_RINIT(say_ke),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(say_ke),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(say_ke),
	PHP_SAY_KE_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_SAY_KE
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(say_ke)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
