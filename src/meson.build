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
app_srcs = files([])
app_deps = [libfoo_dep]
app_args = []


# Fill in config.h with the build options
conf_data = configuration_data()
conf_data.set('OPT_USE_EXCEPTIONS', not get_option('cpp_eh').contains('none'))
conf_data.set('OPT_USE_RTTI', get_option('cpp_rtti'))
conffile = configure_file(configuration : conf_data,
    input : 'config.h.in',
    output : 'config.h')


# Configure version info
version_data = configuration_data()
version_data.set('name', meson.project_name())
version_data.set('version', meson.project_version())
version_data.set('vcs_tag_placeholder', '@VCS_TAG@')
version_data.set('compiler', cppcomp.get_id())
version_data.set('compiler_version', cppcomp.version())
versionpre = configure_file(configuration : version_data
  , input : 'version.c.in.pre'
  , output : 'version.c.in')
git = find_program('git', required : false)
versionfile = vcs_tag(command : ['git', 'rev-parse', '--short', 'HEAD'], fallback : get_option('buildtype').to_upper()
  , input : versionpre
  , output : 'version.c')
# To get commit number instead of ID: ['git', 'rev-list', '--count', 'HEAD']


# Create the executable target
app_target = executable(meson.project_name(), [app_srcs, versionfile[0]], dependencies : app_deps, install : true, c_args : app_args, cpp_args : app_args)
declare_dependency(sources : versionfile, link_with : app_target)
