#include <ruby.h>
#include "codeconv.h"

static VALUE cLibSylph;
static VALUE eLibSylphError;


VALUE utf8tojis(VALUE self, VALUE invalue) {
	CodeConvFunc conv_func =
		conv_get_code_conv_func("UTF-8", "ISO-2022-JP");

	gint error = 0;

    // 1.8
	//gchar* incharbuf  = (gchar*)STR2CSTR(invalue);
    // 1.9
	gchar* incharbuf  = (gchar*)StringValuePtr(invalue);

	gchar* outcharbuf = conv_func(incharbuf, &error);

	VALUE result = rb_str_new2(outcharbuf);

  	if (error != 0) {
    	rb_raise(eLibSylphError, "Can't convert.");
  	}
  	else {
	  	return result;
  	}
}

void Init_lib_sylph(void) {
	cLibSylph = rb_define_class("LibSylph", rb_cObject);
	eLibSylphError = rb_define_class_under(cLibSylph, "Error", rb_eStandardError);

  	rb_define_singleton_method(cLibSylph, "utf8tojis", utf8tojis, 1);
}
