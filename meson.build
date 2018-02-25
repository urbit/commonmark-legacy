project('cmark', 'c', version : '0.12.0')

version = meson.project_version()

src = ['src/blocks.c',
  'src/inlines.c',
  'src/print.c',
  'src/utf8.c',
  'src/buffer.c',
  'src/node.c',
  'src/blocks.c',
  'src/references.c',
  'src/scanners.c',
  'src/html/html.c',
  'src/html/houdini_href_e.c',
  'src/html/houdini_html_e.c',
  'src/html/houdini_html_u.c'
]

include_dirs = include_directories('src/')

install_headers(['src/cmark.h',
  'src/config.h',
  'src/buffer.h',
  'src/chunk.h',
  'src/references.h',
  'src/debug.h',
  'src/utf8.h',
  'src/node.h',
  'src/buffer.h',
  'src/scanners.h',
  'src/inlines.h',
  'src/html/html_unescape.h',
  'src/html/houdini.h'])

re2c = run_command('re2c', '--case-insensitive', '-b', '-i', '-o', 'src/scanners.c', 'src/scanners.re')
if re2c.returncode() != 0
    errortxt = re2c.stderr().strip()
    error('Re2c failed: ' + errortxt)
endif
# We only support static build, because of
# reliance on u3 memory allocators.

lib = static_library('cmark',
sources: src,
include_directories : include_dirs,
version: version,
c_args : ['-O2', '-Wall', '-std=c99'])

cmark_dep = declare_dependency(include_directories : include_dirs,
  link_with : lib)
