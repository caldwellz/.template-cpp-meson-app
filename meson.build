project('', ['c', 'cpp']
  , version : '0.1.0'
  , license: 'MPL-2.0'
  , meson_version : '>=0.50.0'
  , default_options : ['buildtype=debug', 'warning_level=3', 'cpp_eh=none', 'cpp_rtti=false', 'cpp_std=c++14', 'prefix=/usr/local'])


# Add DEBUG/NDEBUG defines
if get_option('buildtype').to_lower() == 'debug'
  add_project_arguments('-DDEBUG', language: ['c', 'cpp'])
else
  add_project_arguments('-DNDEBUG', language: ['c', 'cpp'])
endif


# Run subdirectory scripts
subdir('src')
