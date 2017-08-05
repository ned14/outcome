/* C interface for result
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: Aug 2017


Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License in the accompanying file
Licence.txt or at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.


Distributed under the Boost Software License, Version 1.0.
(See accompanying file Licence.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef OUTCOME_RESULT_H
#define OUTCOME_RESULT_H

// C compatibility
#define CXX_DECLARE_RESULT(R)                                                                                                                                                                                                                                                                                                  \
  struct result_##R                                                                                                                                                                                                                                                                                                            \
  {                                                                                                                                                                                                                                                                                                                            \
    R value;                                                                                                                                                                                                                                                                                                                   \
    unsigned flags;                                                                                                                                                                                                                                                                                                            \
    int error;                                                                                                                                                                                                                                                                                                                 \
    void *category;                                                                                                                                                                                                                                                                                                            \
  }
#define CXX_RESULT(R) struct result_##R
#define CXX_RESULT_HAS_VALUE(r) (((r).flags & 1) == 1)
#define CXX_RESULT_HAS_ERROR(r) (((r).flags & 1) == 0)
#define CXX_RESULT_ERROR_IS_ERRNO(r) (((r).flags & (1 << 4)) == (1 << 4))
#define CXX_RESULT_SET_ERRNO(r) (errno = CXX_RESULT_HAS_ERROR(r) ? (CXX_RESULT_ERROR_IS_ERRNO(r) ? (r).error : EAGAIN) : 0)

#endif
