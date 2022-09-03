# Get compiler details - used in version info and finding dependencies
cppcomp = meson.get_compiler('cpp')


# Find dependencies
# Example of a required library with a subproject fallback
libfoo_dep = dependency('libfoo', required : false)
if not libfoo_dep.found()
  libfoo_dep = cppcomp.find_library('foo', has_headers : ['foo.h'], required : false)
  if not libfoo_dep.found()
    libfoo_proj = subproject('foo')
    libfoo_dep = libfoo_proj.get_variable('libfoo_dep')
  endif
endif


# List sources, dependencies, and any extra compiler arguments - version file comes later
app_srcs = files(['main.cpp'])
app_deps = [libfoo_dep]
app_args = []


# Fill in config.h with the build options
conf_data = configuration_data()
conf_data.set('OPT_USE_EXCEPTIONS', not get_option('cpp_eh').contains('none'))
conf_data.set('OPT_USE_RTTI', get_option('cpp_rtti'))
conffile = configure_file(configuration : conf_data
  , input : 'config.h.in'
  , output : 'config.h')


# Obtain version info from Meson and git (or use defaults if git data is not found)
version_str = meson.project_version()
version_parts = version_str.split('.')
revision_num = 0
revision_commit = 'unknown'
git = find_program('git', required : false)
if git.found()
  tagres = run_command(git, 'rev-parse', '--short', 'HEAD'
    , capture : true
    , check : false)
  if tagres.returncode() == 0
    revision_commit = tagres.stdout().strip()
    revision_num = run_command(git, 'rev-list', '--count', 'HEAD', capture : true, check : false).stdout().strip()
  endif
endif


# Configure version file
version_data = configuration_data()
version_data.set('publisher', get_option('PUBLISHER_NAME'))
version_data.set('description', get_option('PRODUCT_DESCRIPTION'))
version_data.set('name', meson.project_name())
version_data.set('version', version_str)
version_data.set('version_major', version_parts[0])
version_data.set('version_minor', version_parts[1])
version_data.set('version_patch', version_parts[2])
version_data.set('revision_num', revision_num)
version_data.set('revision_commit', revision_commit)
version_data.set('build_type', get_option('buildtype').to_lower())
version_data.set('compiler', cppcomp.get_id())
version_data.set('compiler_version', cppcomp.version())
versionfile = configure_file(configuration : version_data
  , input : 'version.c.in'
  , output : 'version.c')


# Configure and build the Windows resource file
if host_machine.system() == 'windows'
  apprcfile = configure_file(configuration : version_data
    , input : 'res/win32/app.rc.in'
    , output : 'app.rc')
  icofile = configure_file(copy : true
    , input : 'res/win32/app.ico'
    , output : 'app.ico')
  app_srcs += import('windows').compile_resources(apprcfile
    , depend_files : [icofile])
endif

# Create the executable target
app_target = executable(meson.project_name(), [app_srcs, versionfile], dependencies : app_deps, install : true, c_args : app_args, cpp_args : app_args)
declare_dependency(sources : versionfile, link_with : app_target)
