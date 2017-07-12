#ifndef SCM_GLOBAL_H
#define SCM_GLOBAL_H

#if defined(SCM_LIBRARY)
#  define SCMSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SCMSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SCM_GLOBAL_H
