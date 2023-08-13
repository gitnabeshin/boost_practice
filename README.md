# Boost study

## install (Mac)

reftered to this page.

* https://www.boost.org/doc/libs/1_82_0/more/getting_started/unix-variants.html
* http://www.kmonos.net/alang/boost/

### install boost

```
% brew install boost
```

### Run sample code

build in VSCode.

```
#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    std::for_each(
        in(std::cin), in(), std::cout << (_1 * 3) << " " );
}
```

```
% g++ -std=c++17 ./main.cpp
% ./a.out       
1
3 
4
12 
q
% 
```

## boost library

add -l option if needed.

```
nabeshin@iMacNabeshin ~ % ls /usr/local/Cellar/boost/1.82.0_1/lib | grep dylib  
libboost_atomic-mt.dylib
libboost_chrono-mt.dylib
libboost_chrono.dylib
libboost_container-mt.dylib
libboost_container.dylib
libboost_context-mt.dylib
libboost_contract-mt.dylib
libboost_contract.dylib
libboost_coroutine-mt.dylib
libboost_coroutine.dylib
libboost_date_time-mt.dylib
libboost_date_time.dylib
libboost_fiber-mt.dylib
libboost_filesystem-mt.dylib
libboost_filesystem.dylib
libboost_graph-mt.dylib
libboost_graph.dylib
libboost_iostreams-mt.dylib
libboost_iostreams.dylib
libboost_json-mt.dylib
libboost_json.dylib
libboost_locale-mt.dylib
libboost_log-mt.dylib
libboost_log.dylib
libboost_log_setup-mt.dylib
libboost_log_setup.dylib
libboost_math_c99-mt.dylib
libboost_math_c99.dylib
libboost_math_c99f-mt.dylib
libboost_math_c99f.dylib
libboost_math_c99l-mt.dylib
libboost_math_c99l.dylib
libboost_math_tr1-mt.dylib
libboost_math_tr1.dylib
libboost_math_tr1f-mt.dylib
libboost_math_tr1f.dylib
libboost_math_tr1l-mt.dylib
libboost_math_tr1l.dylib
libboost_nowide-mt.dylib
libboost_nowide.dylib
libboost_prg_exec_monitor-mt.dylib
libboost_prg_exec_monitor.dylib
libboost_program_options-mt.dylib
libboost_program_options.dylib
libboost_random-mt.dylib
libboost_random.dylib
libboost_regex-mt.dylib
libboost_regex.dylib
libboost_serialization-mt.dylib
libboost_serialization.dylib
libboost_stacktrace_addr2line-mt.dylib
libboost_stacktrace_addr2line.dylib
libboost_stacktrace_basic-mt.dylib
libboost_stacktrace_basic.dylib
libboost_stacktrace_noop-mt.dylib
libboost_stacktrace_noop.dylib
libboost_system-mt.dylib
libboost_system.dylib
libboost_thread-mt.dylib
libboost_timer-mt.dylib
libboost_timer.dylib
libboost_type_erasure-mt.dylib
libboost_type_erasure.dylib
libboost_unit_test_framework-mt.dylib
libboost_unit_test_framework.dylib
libboost_url-mt.dylib
libboost_url.dylib
libboost_wave-mt.dylib
libboost_wave.dylib
libboost_wserialization-mt.dylib
libboost_wserialization.dylib
nabeshin@iMacNabeshin ~ % 
```