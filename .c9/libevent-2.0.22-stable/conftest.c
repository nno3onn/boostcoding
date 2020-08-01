/* confdefs.h */
#define PACKAGE_NAME ""
#define PACKAGE_TARNAME ""
#define PACKAGE_VERSION ""
#define PACKAGE_STRING ""
#define PACKAGE_BUGREPORT ""
#define PACKAGE_URL ""
#define PACKAGE "libevent"
#define VERSION "2.0.22-stable"
#define NUMERIC_VERSION 0x02001600
#define STDC_HEADERS 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_SYS_STAT_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRING_H 1
#define HAVE_MEMORY_H 1
#define HAVE_STRINGS_H 1
#define HAVE_INTTYPES_H 1
#define HAVE_STDINT_H 1
#define HAVE_UNISTD_H 1
#define HAVE_DLFCN_H 1
#define LT_OBJDIR ".libs/"
#define HAVE_ZLIB_H 1
#define HAVE_LIBZ 1
#define HAVE_OPENSSL_BIO_H 1
#define HAVE_OPENSSL 1
#define STDC_HEADERS 1
#define HAVE_FCNTL_H 1
#define HAVE_STDARG_H 1
#define HAVE_INTTYPES_H 1
#define HAVE_STDINT_H 1
#define HAVE_STDDEF_H 1
#define HAVE_POLL_H 1
#define HAVE_UNISTD_H 1
#define HAVE_SYS_EPOLL_H 1
#define HAVE_SYS_TIME_H 1
#define HAVE_SYS_QUEUE_H 1
#define HAVE_SYS_PARAM_H 1
#define HAVE_SYS_IOCTL_H 1
#define HAVE_SYS_SELECT_H 1
#define HAVE_NETINET_IN_H 1
#define HAVE_SYS_SOCKET_H 1
#define HAVE_SYS_UIO_H 1
#define HAVE_ARPA_INET_H 1
#define HAVE_SYS_EVENTFD_H 1
#define HAVE_SYS_MMAN_H 1
#define HAVE_SYS_SENDFILE_H 1
#define HAVE_SYS_WAIT_H 1
#define HAVE_NETDB_H 1
#define HAVE_SYS_STAT_H 1
#define HAVE_SYS_SYSCTL_H 1
#define HAVE_TAILQFOREACH 1
#define HAVE_TIMERADD 1
#define HAVE_TIMERCMP 1
#define HAVE_TIMERCLEAR 1
#define HAVE_TIMERISSET 1
#define HAVE_DECL_CTL_KERN 1
#define HAVE_DECL_KERN_RANDOM 1
#define HAVE_DECL_RANDOM_UUID 1
#define HAVE_DECL_KERN_ARND 0
#ifndef __cplusplus
#define inline 
#endif
#define TIME_WITH_SYS_TIME 1
#define HAVE_GETTIMEOFDAY 1
#define HAVE_FCNTL 1
#define HAVE_CLOCK_GETTIME 1
#define HAVE_STRTOK_R 1
#define HAVE_STRSEP 1
#define HAVE_GETNAMEINFO 1
#define HAVE_INET_NTOP 1
#define HAVE_INET_PTON 1
#define HAVE_SIGNAL 1
#define HAVE_SIGACTION 1
#define HAVE_INET_ATON 1
#define HAVE_PIPE 1
#define HAVE_EVENTFD 1
#define HAVE_SENDFILE 1
#define HAVE_MMAP 1
/* end confdefs.h.  */
/* Define splice to an innocuous variant, in case <limits.h> declares splice.
   For example, HP-UX 11i <limits.h> declares gettimeofday.  */
#define splice innocuous_splice

/* System header to define __stub macros and hopefully few prototypes,
    which can conflict with char splice (); below.
    Prefer <limits.h> to <assert.h> if __STDC__ is defined, since
    <limits.h> exists even on freestanding compilers.  */

#ifdef __STDC__
# include <limits.h>
#else
# include <assert.h>
#endif

#undef splice

/* Override any GCC internal prototype to avoid an error.
   Use char because int might match the return type of a GCC
   builtin and then its argument prototype would still apply.  */
#ifdef __cplusplus
extern "C"
#endif
char splice ();
/* The GNU C library defines this for functions which it implements
    to always fail with ENOSYS.  Some functions are actually named
    something starting with __ and the normal name is an alias.  */
#if defined __stub_splice || defined __stub___splice
choke me
#endif

int
main ()
{
return splice ();
  ;
  return 0;
}
