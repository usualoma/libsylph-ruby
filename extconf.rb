#!ruby

require "mkmf"

pkg_config  = arg_config('pkg-config', 'pkg-config')
$CFLAGS    += ' ' + `#{pkg_config} glib-2.0 --cflags`.chomp

$libs=append_library($libs, 'sylph')

create_makefile("lib_sylph")
