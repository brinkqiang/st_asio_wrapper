/*
 * st_asio_wrapper_verification.h
 *
 *  Created on: 2012-10-21
 *      Author: youngwolf
 *		email: mail2tao@163.com
 *		QQ: 676218192
 *		Community on QQ: 198941541
 *
 * this head file contain some macros used to verify the compiler and update logs etc.

 * license: www.boost.org/LICENSE_1_0.txt
 *
 * change log:
 * 2012.7.7
 * Created
 *
 * 2012.7.7 - 2016.7.7
 * Beta edition
 *
 * 2016.7.7		version 1.0.0
 * First release
 *
 * 2016.7.17	version 1.0.1
 * Support boost-1.49, it's the minimum version for st_asio_wrapper because of boost::container.
 *
 * 2016.8.7	version 1.1.0
 * Add stream_unpacker to receive native data.
 * asio_server and test_client are now able to start with configurable thread number.
 * Add efficiency statistic for performance tuning, and it can be shut down.
 * Add pingpong test.
 * Move packers and unpackers out of 'include' directory (now in 'ext' directory), they don't belong to st_asio_wrapper library.
 *
 */

#ifndef ST_ASIO_WRAPPER_H_
#define ST_ASIO_WRAPPER_H_

#define ST_ASIO_WRAPPER_VER		10100	//[x]xyyzz -> [x]x.[y]y.[z]z
#define ST_ASIO_WRAPPER_VERSION	"1.1.0"

#ifdef _MSC_VER
	static_assert(_MSC_VER >= 1600, "st_asio_wrapper must be compiled with Visual C++ 10.0 or higher.");
#elif defined(__GNUC__)
	//After a roughly reading from gcc.gnu.org and clang.llvm.org, I believed that the minimum version of GCC and Clang that support c++0x
	//are 4.6 and 3.1, so, I supply the following compiler verification. If there's something wrong, you can freely modify them,
	//and if you let me know, I'll be very appreciated.
	#ifdef __clang__
		static_assert(__clang_major__ > 3 || __clang_major__ == 3 && __clang_minor__ >= 1, "st_asio_wrapper must be compiled with Clang 3.1 or higher.");
	#elif __GNUC__ < 4 || __GNUC__ == 4 && __GNUC_MINOR__ < 6
		#error st_asio_wrapper must be compiled with GCC 4.6 or higher.
	#endif

	#if !defined(__GXX_EXPERIMENTAL_CXX0X__) && (!defined(__cplusplus) || __cplusplus < 201103L)
		#error st_asio_wrapper(standard edition) need c++0x support, please open these features.
	#endif
#else
	#error st_asio_wrapper only support Visual C++, GCC and Clang.
#endif

static_assert(BOOST_VERSION >= 104900, "st_asio_wrapper only support boost 1.49 or higher.");

#endif /* ST_ASIO_WRAPPER_H_ */
