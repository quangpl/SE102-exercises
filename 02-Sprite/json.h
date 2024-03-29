
#define INCLUDE_NLOHMANN_JSON_HPP_

#define NLOHMANN_JSON_VERSION_MAJOR 3
#define NLOHMANN_JSON_VERSION_MINOR 7
#define NLOHMANN_JSON_VERSION_PATCH 0

#include <algorithm> // all_of, find, for_each
#include <cassert> // assert
#include <ciso646> // and, not, or
#include <cstddef> // nullptr_t, ptrdiff_t, size_t
#include <functional> // hash, less
#include <initializer_list> // initializer_list
#include <iosfwd> // istream, ostream
#include <iterator> // random_access_iterator_tag
#include <memory> // unique_ptr
#include <numeric> // accumulate
#include <string> // string, stoi, to_string
#include <utility> // declval, forward, move, pair, swap
#include <vector> // vector

// #include <nlohmann/adl_serializer.hpp>


#include <utility>

// #include <nlohmann/detail/conversions/from_json.hpp>


#include <algorithm> // transform
#include <array> // array
#include <ciso646> // and, not
#include <forward_list> // forward_list
#include <iterator> // inserter, front_inserter, end
#include <map> // map
#include <string> // string
#include <tuple> // tuple, make_tuple
#include <type_traits> // is_arithmetic, is_same, is_enum, underlying_type, is_convertible
#include <unordered_map> // unordered_map
#include <utility> // pair, declval
#include <valarray> // valarray

// #include <nlohmann/detail/exceptions.hpp>


#include <exception> // exception
#include <stdexcept> // runtime_error
#include <string> // to_string

// #include <nlohmann/detail/input/position_t.hpp>


#include <cstddef> // size_t

namespace nlohmann
{
	namespace detail
	{
		/// struct to capture the start position of the current token
		struct position_t
		{
			/// the total number of characters read
			std::size_t chars_read_total = 0;
			/// the number of characters read in the current line
			std::size_t chars_read_current_line = 0;
			/// the number of lines read
			std::size_t lines_read = 0;

			/// conversion to size_t to preserve SAX interface
			constexpr operator size_t() const
			{
				return chars_read_total;
			}
		};

	} // namespace detail
} // namespace nlohmann

// #include <nlohmann/detail/macro_scope.hpp>


#include <utility> // pair
// #include <nlohmann/thirdparty/hedley/hedley.hpp>
/* Hedley - https://nemequ.github.io/hedley
 * Created by Evan Nemerson <evan@nemerson.com>
 *
 * To the extent possible under law, the author(s) have dedicated all
 * copyright and related and neighboring rights to this software to
 * the public domain worldwide. This software is distributed without
 * any warranty.
 *
 * For details, see <http://creativecommons.org/publicdomain/zero/1.0/>.
 * SPDX-License-Identifier: CC0-1.0
 */

#if !defined(JSON_HEDLEY_VERSION) || (JSON_HEDLEY_VERSION < 9)
#if defined(JSON_HEDLEY_VERSION)
#undef JSON_HEDLEY_VERSION
#endif
#define JSON_HEDLEY_VERSION 9

#if defined(JSON_HEDLEY_STRINGIFY_EX)
#undef JSON_HEDLEY_STRINGIFY_EX
#endif
#define JSON_HEDLEY_STRINGIFY_EX(x) #x

#if defined(JSON_HEDLEY_STRINGIFY)
#undef JSON_HEDLEY_STRINGIFY
#endif
#define JSON_HEDLEY_STRINGIFY(x) JSON_HEDLEY_STRINGIFY_EX(x)

#if defined(JSON_HEDLEY_CONCAT_EX)
#undef JSON_HEDLEY_CONCAT_EX
#endif
#define JSON_HEDLEY_CONCAT_EX(a,b) a##b

#if defined(JSON_HEDLEY_CONCAT)
#undef JSON_HEDLEY_CONCAT
#endif
#define JSON_HEDLEY_CONCAT(a,b) JSON_HEDLEY_CONCAT_EX(a,b)

#if defined(JSON_HEDLEY_VERSION_ENCODE)
#undef JSON_HEDLEY_VERSION_ENCODE
#endif
#define JSON_HEDLEY_VERSION_ENCODE(major,minor,revision) (((major) * 1000000) + ((minor) * 1000) + (revision))

#if defined(JSON_HEDLEY_VERSION_DECODE_MAJOR)
#undef JSON_HEDLEY_VERSION_DECODE_MAJOR
#endif
#define JSON_HEDLEY_VERSION_DECODE_MAJOR(version) ((version) / 1000000)

#if defined(JSON_HEDLEY_VERSION_DECODE_MINOR)
#undef JSON_HEDLEY_VERSION_DECODE_MINOR
#endif
#define JSON_HEDLEY_VERSION_DECODE_MINOR(version) (((version) % 1000000) / 1000)

#if defined(JSON_HEDLEY_VERSION_DECODE_REVISION)
#undef JSON_HEDLEY_VERSION_DECODE_REVISION
#endif
#define JSON_HEDLEY_VERSION_DECODE_REVISION(version) ((version) % 1000)

#if defined(JSON_HEDLEY_GNUC_VERSION)
#undef JSON_HEDLEY_GNUC_VERSION
#endif
#if defined(__GNUC__) && defined(__GNUC_PATCHLEVEL__)
#define JSON_HEDLEY_GNUC_VERSION JSON_HEDLEY_VERSION_ENCODE(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
#elif defined(__GNUC__)
#define JSON_HEDLEY_GNUC_VERSION JSON_HEDLEY_VERSION_ENCODE(__GNUC__, __GNUC_MINOR__, 0)
#endif

#if defined(JSON_HEDLEY_GNUC_VERSION_CHECK)
#undef JSON_HEDLEY_GNUC_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_GNUC_VERSION)
#define JSON_HEDLEY_GNUC_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_GNUC_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#define JSON_HEDLEY_GNUC_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(JSON_HEDLEY_MSVC_VERSION)
#undef JSON_HEDLEY_MSVC_VERSION
#endif
#if defined(_MSC_FULL_VER) && (_MSC_FULL_VER >= 140000000)
#define JSON_HEDLEY_MSVC_VERSION JSON_HEDLEY_VERSION_ENCODE(_MSC_FULL_VER / 10000000, (_MSC_FULL_VER % 10000000) / 100000, (_MSC_FULL_VER % 100000) / 100)
#elif defined(_MSC_FULL_VER)
#define JSON_HEDLEY_MSVC_VERSION JSON_HEDLEY_VERSION_ENCODE(_MSC_FULL_VER / 1000000, (_MSC_FULL_VER % 1000000) / 10000, (_MSC_FULL_VER % 10000) / 10)
#elif defined(_MSC_VER)
#define JSON_HEDLEY_MSVC_VERSION JSON_HEDLEY_VERSION_ENCODE(_MSC_VER / 100, _MSC_VER % 100, 0)
#endif

#if defined(JSON_HEDLEY_MSVC_VERSION_CHECK)
#undef JSON_HEDLEY_MSVC_VERSION_CHECK
#endif
#if !defined(_MSC_VER)
#define JSON_HEDLEY_MSVC_VERSION_CHECK(major,minor,patch) (0)
#elif defined(_MSC_VER) && (_MSC_VER >= 1400)
#define JSON_HEDLEY_MSVC_VERSION_CHECK(major,minor,patch) (_MSC_FULL_VER >= ((major * 10000000) + (minor * 100000) + (patch)))
#elif defined(_MSC_VER) && (_MSC_VER >= 1200)
#define JSON_HEDLEY_MSVC_VERSION_CHECK(major,minor,patch) (_MSC_FULL_VER >= ((major * 1000000) + (minor * 10000) + (patch)))
#else
#define JSON_HEDLEY_MSVC_VERSION_CHECK(major,minor,patch) (_MSC_VER >= ((major * 100) + (minor)))
#endif

#if defined(JSON_HEDLEY_INTEL_VERSION)
#undef JSON_HEDLEY_INTEL_VERSION
#endif
#if defined(__INTEL_COMPILER) && defined(__INTEL_COMPILER_UPDATE)
#define JSON_HEDLEY_INTEL_VERSION JSON_HEDLEY_VERSION_ENCODE(__INTEL_COMPILER / 100, __INTEL_COMPILER % 100, __INTEL_COMPILER_UPDATE)
#elif defined(__INTEL_COMPILER)
#define JSON_HEDLEY_INTEL_VERSION JSON_HEDLEY_VERSION_ENCODE(__INTEL_COMPILER / 100, __INTEL_COMPILER % 100, 0)
#endif

#if defined(JSON_HEDLEY_INTEL_VERSION_CHECK)
#undef JSON_HEDLEY_INTEL_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_INTEL_VERSION)
#define JSON_HEDLEY_INTEL_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_INTEL_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#define JSON_HEDLEY_INTEL_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(JSON_HEDLEY_PGI_VERSION)
#undef JSON_HEDLEY_PGI_VERSION
#endif
#if defined(__PGI) && defined(__PGIC__) && defined(__PGIC_MINOR__) && defined(__PGIC_PATCHLEVEL__)
#define JSON_HEDLEY_PGI_VERSION JSON_HEDLEY_VERSION_ENCODE(__PGIC__, __PGIC_MINOR__, __PGIC_PATCHLEVEL__)
#endif

#if defined(JSON_HEDLEY_PGI_VERSION_CHECK)
#undef JSON_HEDLEY_PGI_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_PGI_VERSION)
#define JSON_HEDLEY_PGI_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_PGI_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#define JSON_HEDLEY_PGI_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(JSON_HEDLEY_SUNPRO_VERSION)
#undef JSON_HEDLEY_SUNPRO_VERSION
#endif
#if defined(__SUNPRO_C) && (__SUNPRO_C > 0x1000)
#define JSON_HEDLEY_SUNPRO_VERSION JSON_HEDLEY_VERSION_ENCODE((((__SUNPRO_C >> 16) & 0xf) * 10) + ((__SUNPRO_C >> 12) & 0xf), (((__SUNPRO_C >> 8) & 0xf) * 10) + ((__SUNPRO_C >> 4) & 0xf), (__SUNPRO_C & 0xf) * 10)
#elif defined(__SUNPRO_C)
#define JSON_HEDLEY_SUNPRO_VERSION JSON_HEDLEY_VERSION_ENCODE((__SUNPRO_C >> 8) & 0xf, (__SUNPRO_C >> 4) & 0xf, (__SUNPRO_C) & 0xf)
#elif defined(__SUNPRO_CC) && (__SUNPRO_CC > 0x1000)
#define JSON_HEDLEY_SUNPRO_VERSION JSON_HEDLEY_VERSION_ENCODE((((__SUNPRO_CC >> 16) & 0xf) * 10) + ((__SUNPRO_CC >> 12) & 0xf), (((__SUNPRO_CC >> 8) & 0xf) * 10) + ((__SUNPRO_CC >> 4) & 0xf), (__SUNPRO_CC & 0xf) * 10)
#elif defined(__SUNPRO_CC)
#define JSON_HEDLEY_SUNPRO_VERSION JSON_HEDLEY_VERSION_ENCODE((__SUNPRO_CC >> 8) & 0xf, (__SUNPRO_CC >> 4) & 0xf, (__SUNPRO_CC) & 0xf)
#endif

#if defined(JSON_HEDLEY_SUNPRO_VERSION_CHECK)
#undef JSON_HEDLEY_SUNPRO_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_SUNPRO_VERSION)
#define JSON_HEDLEY_SUNPRO_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_SUNPRO_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#define JSON_HEDLEY_SUNPRO_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(JSON_HEDLEY_EMSCRIPTEN_VERSION)
#undef JSON_HEDLEY_EMSCRIPTEN_VERSION
#endif
#if defined(__EMSCRIPTEN__)
#define JSON_HEDLEY_EMSCRIPTEN_VERSION JSON_HEDLEY_VERSION_ENCODE(__EMSCRIPTEN_major__, __EMSCRIPTEN_minor__, __EMSCRIPTEN_tiny__)
#endif

#if defined(JSON_HEDLEY_EMSCRIPTEN_VERSION_CHECK)
#undef JSON_HEDLEY_EMSCRIPTEN_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_EMSCRIPTEN_VERSION)
#define JSON_HEDLEY_EMSCRIPTEN_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_EMSCRIPTEN_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#define JSON_HEDLEY_EMSCRIPTEN_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(JSON_HEDLEY_ARM_VERSION)
#undef JSON_HEDLEY_ARM_VERSION
#endif
#if defined(__CC_ARM) && defined(__ARMCOMPILER_VERSION)
#define JSON_HEDLEY_ARM_VERSION JSON_HEDLEY_VERSION_ENCODE(__ARMCOMPILER_VERSION / 1000000, (__ARMCOMPILER_VERSION % 1000000) / 10000, (__ARMCOMPILER_VERSION % 10000) / 100)
#elif defined(__CC_ARM) && defined(__ARMCC_VERSION)
#define JSON_HEDLEY_ARM_VERSION JSON_HEDLEY_VERSION_ENCODE(__ARMCC_VERSION / 1000000, (__ARMCC_VERSION % 1000000) / 10000, (__ARMCC_VERSION % 10000) / 100)
#endif

#if defined(JSON_HEDLEY_ARM_VERSION_CHECK)
#undef JSON_HEDLEY_ARM_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_ARM_VERSION)
#define JSON_HEDLEY_ARM_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_ARM_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#define JSON_HEDLEY_ARM_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(JSON_HEDLEY_IBM_VERSION)
#undef JSON_HEDLEY_IBM_VERSION
#endif
#if defined(__ibmxl__)
#define JSON_HEDLEY_IBM_VERSION JSON_HEDLEY_VERSION_ENCODE(__ibmxl_version__, __ibmxl_release__, __ibmxl_modification__)
#elif defined(__xlC__) && defined(__xlC_ver__)
#define JSON_HEDLEY_IBM_VERSION JSON_HEDLEY_VERSION_ENCODE(__xlC__ >> 8, __xlC__ & 0xff, (__xlC_ver__ >> 8) & 0xff)
#elif defined(__xlC__)
#define JSON_HEDLEY_IBM_VERSION JSON_HEDLEY_VERSION_ENCODE(__xlC__ >> 8, __xlC__ & 0xff, 0)
#endif

#if defined(JSON_HEDLEY_IBM_VERSION_CHECK)
#undef JSON_HEDLEY_IBM_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_IBM_VERSION)
#define JSON_HEDLEY_IBM_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_IBM_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#define JSON_HEDLEY_IBM_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(JSON_HEDLEY_TI_VERSION)
#undef JSON_HEDLEY_TI_VERSION
#endif
#if defined(__TI_COMPILER_VERSION__)
#define JSON_HEDLEY_TI_VERSION JSON_HEDLEY_VERSION_ENCODE(__TI_COMPILER_VERSION__ / 1000000, (__TI_COMPILER_VERSION__ % 1000000) / 1000, (__TI_COMPILER_VERSION__ % 1000))
#endif

#if defined(JSON_HEDLEY_TI_VERSION_CHECK)
#undef JSON_HEDLEY_TI_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_TI_VERSION)
#define JSON_HEDLEY_TI_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_TI_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#define JSON_HEDLEY_TI_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(JSON_HEDLEY_CRAY_VERSION)
#undef JSON_HEDLEY_CRAY_VERSION
#endif
#if defined(_CRAYC)
#if defined(_RELEASE_PATCHLEVEL)
#define JSON_HEDLEY_CRAY_VERSION JSON_HEDLEY_VERSION_ENCODE(_RELEASE_MAJOR, _RELEASE_MINOR, _RELEASE_PATCHLEVEL)
#else
#define JSON_HEDLEY_CRAY_VERSION JSON_HEDLEY_VERSION_ENCODE(_RELEASE_MAJOR, _RELEASE_MINOR, 0)
#endif
#endif

#if defined(JSON_HEDLEY_CRAY_VERSION_CHECK)
#undef JSON_HEDLEY_CRAY_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_CRAY_VERSION)
#define JSON_HEDLEY_CRAY_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_CRAY_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#define JSON_HEDLEY_CRAY_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(JSON_HEDLEY_IAR_VERSION)
#undef JSON_HEDLEY_IAR_VERSION
#endif
#if defined(__IAR_SYSTEMS_ICC__)
#if __VER__ > 1000
#define JSON_HEDLEY_IAR_VERSION JSON_HEDLEY_VERSION_ENCODE((__VER__ / 1000000), ((__VER__ / 1000) % 1000), (__VER__ % 1000))
#else
#define JSON_HEDLEY_IAR_VERSION JSON_HEDLEY_VERSION_ENCODE(VER / 100, __VER__ % 100, 0)
#endif
#endif

#if defined(JSON_HEDLEY_IAR_VERSION_CHECK)
#undef JSON_HEDLEY_IAR_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_IAR_VERSION)
#define JSON_HEDLEY_IAR_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_IAR_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#define JSON_HEDLEY_IAR_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(JSON_HEDLEY_TINYC_VERSION)
#undef JSON_HEDLEY_TINYC_VERSION
#endif
#if defined(__TINYC__)
#define JSON_HEDLEY_TINYC_VERSION JSON_HEDLEY_VERSION_ENCODE(__TINYC__ / 1000, (__TINYC__ / 100) % 10, __TINYC__ % 100)
#endif

#if defined(JSON_HEDLEY_TINYC_VERSION_CHECK)
#undef JSON_HEDLEY_TINYC_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_TINYC_VERSION)
#define JSON_HEDLEY_TINYC_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_TINYC_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#define JSON_HEDLEY_TINYC_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(JSON_HEDLEY_DMC_VERSION)
#undef JSON_HEDLEY_DMC_VERSION
#endif
#if defined(__DMC__)
#define JSON_HEDLEY_DMC_VERSION JSON_HEDLEY_VERSION_ENCODE(__DMC__ >> 8, (__DMC__ >> 4) & 0xf, __DMC__ & 0xf)
#endif

#if defined(JSON_HEDLEY_DMC_VERSION_CHECK)
#undef JSON_HEDLEY_DMC_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_DMC_VERSION)
#define JSON_HEDLEY_DMC_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_DMC_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#define JSON_HEDLEY_DMC_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(JSON_HEDLEY_COMPCERT_VERSION)
#undef JSON_HEDLEY_COMPCERT_VERSION
#endif
#if defined(__COMPCERT_VERSION__)
#define JSON_HEDLEY_COMPCERT_VERSION JSON_HEDLEY_VERSION_ENCODE(__COMPCERT_VERSION__ / 10000, (__COMPCERT_VERSION__ / 100) % 100, __COMPCERT_VERSION__ % 100)
#endif

#if defined(JSON_HEDLEY_COMPCERT_VERSION_CHECK)
#undef JSON_HEDLEY_COMPCERT_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_COMPCERT_VERSION)
#define JSON_HEDLEY_COMPCERT_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_COMPCERT_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#define JSON_HEDLEY_COMPCERT_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(JSON_HEDLEY_PELLES_VERSION)
#undef JSON_HEDLEY_PELLES_VERSION
#endif
#if defined(__POCC__)
#define JSON_HEDLEY_PELLES_VERSION JSON_HEDLEY_VERSION_ENCODE(__POCC__ / 100, __POCC__ % 100, 0)
#endif

#if defined(JSON_HEDLEY_PELLES_VERSION_CHECK)
#undef JSON_HEDLEY_PELLES_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_PELLES_VERSION)
#define JSON_HEDLEY_PELLES_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_PELLES_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#define JSON_HEDLEY_PELLES_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(JSON_HEDLEY_GCC_VERSION)
#undef JSON_HEDLEY_GCC_VERSION
#endif
#if \
    defined(JSON_HEDLEY_GNUC_VERSION) && \
    !defined(__clang__) && \
    !defined(JSON_HEDLEY_INTEL_VERSION) && \
    !defined(JSON_HEDLEY_PGI_VERSION) && \
    !defined(JSON_HEDLEY_ARM_VERSION) && \
    !defined(JSON_HEDLEY_TI_VERSION) && \
    !defined(__COMPCERT__)
#define JSON_HEDLEY_GCC_VERSION JSON_HEDLEY_GNUC_VERSION
#endif

#if defined(JSON_HEDLEY_GCC_VERSION_CHECK)
#undef JSON_HEDLEY_GCC_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_GCC_VERSION)
#define JSON_HEDLEY_GCC_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_GCC_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#define JSON_HEDLEY_GCC_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(JSON_HEDLEY_HAS_ATTRIBUTE)
#undef JSON_HEDLEY_HAS_ATTRIBUTE
#endif
#if defined(__has_attribute)
#define JSON_HEDLEY_HAS_ATTRIBUTE(attribute) __has_attribute(attribute)
#else
#define JSON_HEDLEY_HAS_ATTRIBUTE(attribute) (0)
#endif

#if defined(JSON_HEDLEY_GNUC_HAS_ATTRIBUTE)
#undef JSON_HEDLEY_GNUC_HAS_ATTRIBUTE
#endif
#if defined(__has_attribute)
#define JSON_HEDLEY_GNUC_HAS_ATTRIBUTE(attribute,major,minor,patch) __has_attribute(attribute)
#else
#define JSON_HEDLEY_GNUC_HAS_ATTRIBUTE(attribute,major,minor,patch) JSON_HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(JSON_HEDLEY_GCC_HAS_ATTRIBUTE)
#undef JSON_HEDLEY_GCC_HAS_ATTRIBUTE
#endif
#if defined(__has_attribute)
#define JSON_HEDLEY_GCC_HAS_ATTRIBUTE(attribute,major,minor,patch) __has_attribute(attribute)
#else
#define JSON_HEDLEY_GCC_HAS_ATTRIBUTE(attribute,major,minor,patch) JSON_HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(JSON_HEDLEY_HAS_CPP_ATTRIBUTE)
#undef JSON_HEDLEY_HAS_CPP_ATTRIBUTE
#endif
#if defined(__has_cpp_attribute) && defined(__cplusplus)
#define JSON_HEDLEY_HAS_CPP_ATTRIBUTE(attribute) __has_cpp_attribute(attribute)
#else
#define JSON_HEDLEY_HAS_CPP_ATTRIBUTE(attribute) (0)
#endif

#if defined(JSON_HEDLEY_GNUC_HAS_CPP_ATTRIBUTE)
#undef JSON_HEDLEY_GNUC_HAS_CPP_ATTRIBUTE
#endif
#if defined(__has_cpp_attribute) && defined(__cplusplus)
#define JSON_HEDLEY_GNUC_HAS_CPP_ATTRIBUTE(attribute,major,minor,patch) __has_cpp_attribute(attribute)
#else
#define JSON_HEDLEY_GNUC_HAS_CPP_ATTRIBUTE(attribute,major,minor,patch) JSON_HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(JSON_HEDLEY_GCC_HAS_CPP_ATTRIBUTE)
#undef JSON_HEDLEY_GCC_HAS_CPP_ATTRIBUTE
#endif
#if defined(__has_cpp_attribute) && defined(__cplusplus)
#define JSON_HEDLEY_GCC_HAS_CPP_ATTRIBUTE(attribute,major,minor,patch) __has_cpp_attribute(attribute)
#else
#define JSON_HEDLEY_GCC_HAS_CPP_ATTRIBUTE(attribute,major,minor,patch) JSON_HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(JSON_HEDLEY_HAS_BUILTIN)
#undef JSON_HEDLEY_HAS_BUILTIN
#endif
#if defined(__has_builtin)
#define JSON_HEDLEY_HAS_BUILTIN(builtin) __has_builtin(builtin)
#else
#define JSON_HEDLEY_HAS_BUILTIN(builtin) (0)
#endif

#if defined(JSON_HEDLEY_GNUC_HAS_BUILTIN)
#undef JSON_HEDLEY_GNUC_HAS_BUILTIN
#endif
#if defined(__has_builtin)
#define JSON_HEDLEY_GNUC_HAS_BUILTIN(builtin,major,minor,patch) __has_builtin(builtin)
#else
#define JSON_HEDLEY_GNUC_HAS_BUILTIN(builtin,major,minor,patch) JSON_HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(JSON_HEDLEY_GCC_HAS_BUILTIN)
#undef JSON_HEDLEY_GCC_HAS_BUILTIN
#endif
#if defined(__has_builtin)
#define JSON_HEDLEY_GCC_HAS_BUILTIN(builtin,major,minor,patch) __has_builtin(builtin)
#else
#define JSON_HEDLEY_GCC_HAS_BUILTIN(builtin,major,minor,patch) JSON_HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(JSON_HEDLEY_HAS_FEATURE)
#undef JSON_HEDLEY_HAS_FEATURE
#endif
#if defined(__has_feature)
#define JSON_HEDLEY_HAS_FEATURE(feature) __has_feature(feature)
#else
#define JSON_HEDLEY_HAS_FEATURE(feature) (0)
#endif

#if defined(JSON_HEDLEY_GNUC_HAS_FEATURE)
#undef JSON_HEDLEY_GNUC_HAS_FEATURE
#endif
#if defined(__has_feature)
#define JSON_HEDLEY_GNUC_HAS_FEATURE(feature,major,minor,patch) __has_feature(feature)
#else
#define JSON_HEDLEY_GNUC_HAS_FEATURE(feature,major,minor,patch) JSON_HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(JSON_HEDLEY_GCC_HAS_FEATURE)
#undef JSON_HEDLEY_GCC_HAS_FEATURE
#endif
#if defined(__has_feature)
#define JSON_HEDLEY_GCC_HAS_FEATURE(feature,major,minor,patch) __has_feature(feature)
#else
#define JSON_HEDLEY_GCC_HAS_FEATURE(feature,major,minor,patch) JSON_HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(JSON_HEDLEY_HAS_EXTENSION)
#undef JSON_HEDLEY_HAS_EXTENSION
#endif
#if defined(__has_extension)
#define JSON_HEDLEY_HAS_EXTENSION(extension) __has_extension(extension)
#else
#define JSON_HEDLEY_HAS_EXTENSION(extension) (0)
#endif

#if defined(JSON_HEDLEY_GNUC_HAS_EXTENSION)
#undef JSON_HEDLEY_GNUC_HAS_EXTENSION
#endif
#if defined(__has_extension)
#define JSON_HEDLEY_GNUC_HAS_EXTENSION(extension,major,minor,patch) __has_extension(extension)
#else
#define JSON_HEDLEY_GNUC_HAS_EXTENSION(extension,major,minor,patch) JSON_HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(JSON_HEDLEY_GCC_HAS_EXTENSION)
#undef JSON_HEDLEY_GCC_HAS_EXTENSION
#endif
#if defined(__has_extension)
#define JSON_HEDLEY_GCC_HAS_EXTENSION(extension,major,minor,patch) __has_extension(extension)
#else
#define JSON_HEDLEY_GCC_HAS_EXTENSION(extension,major,minor,patch) JSON_HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(JSON_HEDLEY_HAS_DECLSPEC_ATTRIBUTE)
#undef JSON_HEDLEY_HAS_DECLSPEC_ATTRIBUTE
#endif
#if defined(__has_declspec_attribute)
#define JSON_HEDLEY_HAS_DECLSPEC_ATTRIBUTE(attribute) __has_declspec_attribute(attribute)
#else
#define JSON_HEDLEY_HAS_DECLSPEC_ATTRIBUTE(attribute) (0)
#endif

#if defined(JSON_HEDLEY_GNUC_HAS_DECLSPEC_ATTRIBUTE)
#undef JSON_HEDLEY_GNUC_HAS_DECLSPEC_ATTRIBUTE
#endif
#if defined(__has_declspec_attribute)
#define JSON_HEDLEY_GNUC_HAS_DECLSPEC_ATTRIBUTE(attribute,major,minor,patch) __has_declspec_attribute(attribute)
#else
#define JSON_HEDLEY_GNUC_HAS_DECLSPEC_ATTRIBUTE(attribute,major,minor,patch) JSON_HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(JSON_HEDLEY_GCC_HAS_DECLSPEC_ATTRIBUTE)
#undef JSON_HEDLEY_GCC_HAS_DECLSPEC_ATTRIBUTE
#endif
#if defined(__has_declspec_attribute)
#define JSON_HEDLEY_GCC_HAS_DECLSPEC_ATTRIBUTE(attribute,major,minor,patch) __has_declspec_attribute(attribute)
#else
#define JSON_HEDLEY_GCC_HAS_DECLSPEC_ATTRIBUTE(attribute,major,minor,patch) JSON_HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(JSON_HEDLEY_HAS_WARNING)
#undef JSON_HEDLEY_HAS_WARNING
#endif
#if defined(__has_warning)
#define JSON_HEDLEY_HAS_WARNING(warning) __has_warning(warning)
#else
#define JSON_HEDLEY_HAS_WARNING(warning) (0)
#endif

#if defined(JSON_HEDLEY_GNUC_HAS_WARNING)
#undef JSON_HEDLEY_GNUC_HAS_WARNING
#endif
#if defined(__has_warning)
#define JSON_HEDLEY_GNUC_HAS_WARNING(warning,major,minor,patch) __has_warning(warning)
#else
#define JSON_HEDLEY_GNUC_HAS_WARNING(warning,major,minor,patch) JSON_HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(JSON_HEDLEY_GCC_HAS_WARNING)
#undef JSON_HEDLEY_GCC_HAS_WARNING
#endif
#if defined(__has_warning)
#define JSON_HEDLEY_GCC_HAS_WARNING(warning,major,minor,patch) __has_warning(warning)
#else
#define JSON_HEDLEY_GCC_HAS_WARNING(warning,major,minor,patch) JSON_HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#endif

#if \
    (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)) || \
    defined(__clang__) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(3,0,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_IAR_VERSION_CHECK(8,0,0) || \
    JSON_HEDLEY_PGI_VERSION_CHECK(18,4,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
    JSON_HEDLEY_TI_VERSION_CHECK(6,0,0) || \
    JSON_HEDLEY_CRAY_VERSION_CHECK(5,0,0) || \
    JSON_HEDLEY_TINYC_VERSION_CHECK(0,9,17) || \
    JSON_HEDLEY_SUNPRO_VERSION_CHECK(8,0,0) || \
    (JSON_HEDLEY_IBM_VERSION_CHECK(10,1,0) && defined(__C99_PRAGMA_OPERATOR))
#define JSON_HEDLEY_PRAGMA(value) _Pragma(#value)
#elif JSON_HEDLEY_MSVC_VERSION_CHECK(15,0,0)
#define JSON_HEDLEY_PRAGMA(value) __pragma(value)
#else
#define JSON_HEDLEY_PRAGMA(value)
#endif

#if defined(JSON_HEDLEY_DIAGNOSTIC_PUSH)
#undef JSON_HEDLEY_DIAGNOSTIC_PUSH
#endif
#if defined(JSON_HEDLEY_DIAGNOSTIC_POP)
#undef JSON_HEDLEY_DIAGNOSTIC_POP
#endif
#if defined(__clang__)
#define JSON_HEDLEY_DIAGNOSTIC_PUSH _Pragma("clang diagnostic push")
#define JSON_HEDLEY_DIAGNOSTIC_POP _Pragma("clang diagnostic pop")
#elif JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0)
#define JSON_HEDLEY_DIAGNOSTIC_PUSH _Pragma("warning(push)")
#define JSON_HEDLEY_DIAGNOSTIC_POP _Pragma("warning(pop)")
#elif JSON_HEDLEY_GCC_VERSION_CHECK(4,6,0)
#define JSON_HEDLEY_DIAGNOSTIC_PUSH _Pragma("GCC diagnostic push")
#define JSON_HEDLEY_DIAGNOSTIC_POP _Pragma("GCC diagnostic pop")
#elif JSON_HEDLEY_MSVC_VERSION_CHECK(15,0,0)
#define JSON_HEDLEY_DIAGNOSTIC_PUSH __pragma(warning(push))
#define JSON_HEDLEY_DIAGNOSTIC_POP __pragma(warning(pop))
#elif JSON_HEDLEY_ARM_VERSION_CHECK(5,6,0)
#define JSON_HEDLEY_DIAGNOSTIC_PUSH _Pragma("push")
#define JSON_HEDLEY_DIAGNOSTIC_POP _Pragma("pop")
#elif JSON_HEDLEY_TI_VERSION_CHECK(8,1,0)
#define JSON_HEDLEY_DIAGNOSTIC_PUSH _Pragma("diag_push")
#define JSON_HEDLEY_DIAGNOSTIC_POP _Pragma("diag_pop")
#elif JSON_HEDLEY_PELLES_VERSION_CHECK(2,90,0)
#define JSON_HEDLEY_DIAGNOSTIC_PUSH _Pragma("warning(push)")
#define JSON_HEDLEY_DIAGNOSTIC_POP _Pragma("warning(pop)")
#else
#define JSON_HEDLEY_DIAGNOSTIC_PUSH
#define JSON_HEDLEY_DIAGNOSTIC_POP
#endif

#if defined(JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED)
#undef JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED
#endif
#if JSON_HEDLEY_HAS_WARNING("-Wdeprecated-declarations")
#define JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("clang diagnostic ignored \"-Wdeprecated-declarations\"")
#elif JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0)
#define JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("warning(disable:1478 1786)")
#elif JSON_HEDLEY_PGI_VERSION_CHECK(17,10,0)
#define JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("diag_suppress 1215,1444")
#elif JSON_HEDLEY_GCC_VERSION_CHECK(4,3,0)
#define JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("GCC diagnostic ignored \"-Wdeprecated-declarations\"")
#elif JSON_HEDLEY_MSVC_VERSION_CHECK(15,0,0)
#define JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED __pragma(warning(disable:4996))
#elif JSON_HEDLEY_TI_VERSION_CHECK(8,0,0)
#define JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("diag_suppress 1291,1718")
#elif JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,13,0) && !defined(__cplusplus)
#define JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("error_messages(off,E_DEPRECATED_ATT,E_DEPRECATED_ATT_MESS)")
#elif JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,13,0) && defined(__cplusplus)
#define JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("error_messages(off,symdeprecated,symdeprecated2)")
#elif JSON_HEDLEY_IAR_VERSION_CHECK(8,0,0)
#define JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("diag_suppress=Pe1444,Pe1215")
#elif JSON_HEDLEY_PELLES_VERSION_CHECK(2,90,0)
#define JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("warn(disable:2241)")
#else
#define JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED
#endif

#if defined(JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS)
#undef JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS
#endif
#if JSON_HEDLEY_HAS_WARNING("-Wunknown-pragmas")
#define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("clang diagnostic ignored \"-Wunknown-pragmas\"")
#elif JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0)
#define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("warning(disable:161)")
#elif JSON_HEDLEY_PGI_VERSION_CHECK(17,10,0)
#define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("diag_suppress 1675")
#elif JSON_HEDLEY_GCC_VERSION_CHECK(4,3,0)
#define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("GCC diagnostic ignored \"-Wunknown-pragmas\"")
#elif JSON_HEDLEY_MSVC_VERSION_CHECK(15,0,0)
#define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS __pragma(warning(disable:4068))
#elif JSON_HEDLEY_TI_VERSION_CHECK(8,0,0)
#define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("diag_suppress 163")
#elif JSON_HEDLEY_IAR_VERSION_CHECK(8,0,0)
#define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("diag_suppress=Pe161")
#else
#define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS
#endif

#if defined(JSON_HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL)
#undef JSON_HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL
#endif
#if JSON_HEDLEY_HAS_WARNING("-Wcast-qual")
#define JSON_HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL _Pragma("clang diagnostic ignored \"-Wcast-qual\"")
#elif JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0)
#define JSON_HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL _Pragma("warning(disable:2203 2331)")
#elif JSON_HEDLEY_GCC_VERSION_CHECK(3,0,0)
#define JSON_HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL _Pragma("GCC diagnostic ignored \"-Wcast-qual\"")
#else
#define JSON_HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL
#endif

#if defined(JSON_HEDLEY_DEPRECATED)
#undef JSON_HEDLEY_DEPRECATED
#endif
#if defined(JSON_HEDLEY_DEPRECATED_FOR)
#undef JSON_HEDLEY_DEPRECATED_FOR
#endif
#if defined(__cplusplus) && (__cplusplus >= 201402L)
#define JSON_HEDLEY_DEPRECATED(since) [[deprecated("Since " #since)]]
#define JSON_HEDLEY_DEPRECATED_FOR(since, replacement) [[deprecated("Since " #since "; use " #replacement)]]
#elif \
    JSON_HEDLEY_HAS_EXTENSION(attribute_deprecated_with_message) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(4,5,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(5,6,0) || \
    JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,13,0) || \
    JSON_HEDLEY_PGI_VERSION_CHECK(17,10,0) || \
    JSON_HEDLEY_TI_VERSION_CHECK(8,3,0)
#define JSON_HEDLEY_DEPRECATED(since) __attribute__((__deprecated__("Since " #since)))
#define JSON_HEDLEY_DEPRECATED_FOR(since, replacement) __attribute__((__deprecated__("Since " #since "; use " #replacement)))
#elif \
    JSON_HEDLEY_HAS_ATTRIBUTE(deprecated) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(3,1,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
    JSON_HEDLEY_TI_VERSION_CHECK(8,0,0) || \
    (JSON_HEDLEY_TI_VERSION_CHECK(7,3,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__))
#define JSON_HEDLEY_DEPRECATED(since) __attribute__((__deprecated__))
#define JSON_HEDLEY_DEPRECATED_FOR(since, replacement) __attribute__((__deprecated__))
#elif JSON_HEDLEY_MSVC_VERSION_CHECK(14,0,0)
#define JSON_HEDLEY_DEPRECATED(since) __declspec(deprecated("Since " # since))
#define JSON_HEDLEY_DEPRECATED_FOR(since, replacement) __declspec(deprecated("Since " #since "; use " #replacement))
#elif \
    JSON_HEDLEY_MSVC_VERSION_CHECK(13,10,0) || \
    JSON_HEDLEY_PELLES_VERSION_CHECK(6,50,0)
#define JSON_HEDLEY_DEPRECATED(since) _declspec(deprecated)
#define JSON_HEDLEY_DEPRECATED_FOR(since, replacement) __declspec(deprecated)
#elif JSON_HEDLEY_IAR_VERSION_CHECK(8,0,0)
#define JSON_HEDLEY_DEPRECATED(since) _Pragma("deprecated")
#define JSON_HEDLEY_DEPRECATED_FOR(since, replacement) _Pragma("deprecated")
#else
#define JSON_HEDLEY_DEPRECATED(since)
#define JSON_HEDLEY_DEPRECATED_FOR(since, replacement)
#endif

#if defined(JSON_HEDLEY_UNAVAILABLE)
#undef JSON_HEDLEY_UNAVAILABLE
#endif
#if \
    JSON_HEDLEY_HAS_ATTRIBUTE(warning) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(4,3,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0)
#define JSON_HEDLEY_UNAVAILABLE(available_since) __attribute__((__warning__("Not available until " #available_since)))
#else
#define JSON_HEDLEY_UNAVAILABLE(available_since)
#endif

#if defined(JSON_HEDLEY_WARN_UNUSED_RESULT)
#undef JSON_HEDLEY_WARN_UNUSED_RESULT
#endif
#if defined(__cplusplus) && (__cplusplus >= 201703L)
#define JSON_HEDLEY_WARN_UNUSED_RESULT [[nodiscard]]
#elif \
    JSON_HEDLEY_HAS_ATTRIBUTE(warn_unused_result) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(3,4,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_TI_VERSION_CHECK(8,0,0) || \
    (JSON_HEDLEY_TI_VERSION_CHECK(7,3,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    (JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,15,0) && defined(__cplusplus)) || \
    JSON_HEDLEY_PGI_VERSION_CHECK(17,10,0)
#define JSON_HEDLEY_WARN_UNUSED_RESULT __attribute__((__warn_unused_result__))
#elif defined(_Check_return_) /* SAL */
#define JSON_HEDLEY_WARN_UNUSED_RESULT _Check_return_
#else
#define JSON_HEDLEY_WARN_UNUSED_RESULT
#endif

#if defined(JSON_HEDLEY_SENTINEL)
#undef JSON_HEDLEY_SENTINEL
#endif
#if \
    JSON_HEDLEY_HAS_ATTRIBUTE(sentinel) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(4,0,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(5,4,0)
#define JSON_HEDLEY_SENTINEL(position) __attribute__((__sentinel__(position)))
#else
#define JSON_HEDLEY_SENTINEL(position)
#endif

#if defined(JSON_HEDLEY_NO_RETURN)
#undef JSON_HEDLEY_NO_RETURN
#endif
#if JSON_HEDLEY_IAR_VERSION_CHECK(8,0,0)
#define JSON_HEDLEY_NO_RETURN __noreturn
#elif JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0)
#define JSON_HEDLEY_NO_RETURN __attribute__((__noreturn__))
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
#define JSON_HEDLEY_NO_RETURN _Noreturn
#elif defined(__cplusplus) && (__cplusplus >= 201103L)
#define JSON_HEDLEY_NO_RETURN [[noreturn]]
#elif \
    JSON_HEDLEY_HAS_ATTRIBUTE(noreturn) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(3,2,0) || \
    JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,11,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
    JSON_HEDLEY_IBM_VERSION_CHECK(10,1,0) || \
    JSON_HEDLEY_TI_VERSION_CHECK(18,0,0) || \
    (JSON_HEDLEY_TI_VERSION_CHECK(17,3,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__))
#define JSON_HEDLEY_NO_RETURN __attribute__((__noreturn__))
#elif JSON_HEDLEY_MSVC_VERSION_CHECK(13,10,0)
#define JSON_HEDLEY_NO_RETURN __declspec(noreturn)
#elif JSON_HEDLEY_TI_VERSION_CHECK(6,0,0) && defined(__cplusplus)
#define JSON_HEDLEY_NO_RETURN _Pragma("FUNC_NEVER_RETURNS;")
#elif JSON_HEDLEY_COMPCERT_VERSION_CHECK(3,2,0)
#define JSON_HEDLEY_NO_RETURN __attribute((noreturn))
#elif JSON_HEDLEY_PELLES_VERSION_CHECK(9,0,0)
#define JSON_HEDLEY_NO_RETURN __declspec(noreturn)
#else
#define JSON_HEDLEY_NO_RETURN
#endif

#if defined(JSON_HEDLEY_UNREACHABLE)
#undef JSON_HEDLEY_UNREACHABLE
#endif
#if defined(JSON_HEDLEY_UNREACHABLE_RETURN)
#undef JSON_HEDLEY_UNREACHABLE_RETURN
#endif
#if \
    (JSON_HEDLEY_HAS_BUILTIN(__builtin_unreachable) && (!defined(JSON_HEDLEY_ARM_VERSION))) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(4,5,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_IBM_VERSION_CHECK(13,1,5)
#define JSON_HEDLEY_UNREACHABLE() __builtin_unreachable()
#elif JSON_HEDLEY_MSVC_VERSION_CHECK(13,10,0)
#define JSON_HEDLEY_UNREACHABLE() __assume(0)
#elif JSON_HEDLEY_TI_VERSION_CHECK(6,0,0)
#if defined(__cplusplus)
#define JSON_HEDLEY_UNREACHABLE() std::_nassert(0)
#else
#define JSON_HEDLEY_UNREACHABLE() _nassert(0)
#endif
#define JSON_HEDLEY_UNREACHABLE_RETURN(value) return value
#elif defined(EXIT_FAILURE)
#define JSON_HEDLEY_UNREACHABLE() abort()
#else
#define JSON_HEDLEY_UNREACHABLE()
#define JSON_HEDLEY_UNREACHABLE_RETURN(value) return value
#endif
#if !defined(JSON_HEDLEY_UNREACHABLE_RETURN)
#define JSON_HEDLEY_UNREACHABLE_RETURN(value) JSON_HEDLEY_UNREACHABLE()
#endif

#if defined(JSON_HEDLEY_ASSUME)
#undef JSON_HEDLEY_ASSUME
#endif
#if \
    JSON_HEDLEY_MSVC_VERSION_CHECK(13,10,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0)
#define JSON_HEDLEY_ASSUME(expr) __assume(expr)
#elif JSON_HEDLEY_HAS_BUILTIN(__builtin_assume)
#define JSON_HEDLEY_ASSUME(expr) __builtin_assume(expr)
#elif JSON_HEDLEY_TI_VERSION_CHECK(6,0,0)
#if defined(__cplusplus)
#define JSON_HEDLEY_ASSUME(expr) std::_nassert(expr)
#else
#define JSON_HEDLEY_ASSUME(expr) _nassert(expr)
#endif
#elif \
    (JSON_HEDLEY_HAS_BUILTIN(__builtin_unreachable) && !defined(JSON_HEDLEY_ARM_VERSION)) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(4,5,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_IBM_VERSION_CHECK(13,1,5)
#define JSON_HEDLEY_ASSUME(expr) ((void) ((expr) ? 1 : (__builtin_unreachable(), 1)))
#else
#define JSON_HEDLEY_ASSUME(expr) ((void) (expr))
#endif


JSON_HEDLEY_DIAGNOSTIC_PUSH
#if \
    JSON_HEDLEY_HAS_WARNING("-Wvariadic-macros") || \
    JSON_HEDLEY_GCC_VERSION_CHECK(4,0,0)
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wvariadic-macros"
#elif defined(JSON_HEDLEY_GCC_VERSION)
#pragma GCC diagnostic ignored "-Wvariadic-macros"
#endif
#endif
#if defined(JSON_HEDLEY_NON_NULL)
#undef JSON_HEDLEY_NON_NULL
#endif
#if \
    JSON_HEDLEY_HAS_ATTRIBUTE(nonnull) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(3,3,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0)
#define JSON_HEDLEY_NON_NULL(...) __attribute__((__nonnull__(__VA_ARGS__)))
#else
#define JSON_HEDLEY_NON_NULL(...)
#endif
JSON_HEDLEY_DIAGNOSTIC_POP

#if defined(JSON_HEDLEY_PRINTF_FORMAT)
#undef JSON_HEDLEY_PRINTF_FORMAT
#endif
#if defined(__MINGW32__) && JSON_HEDLEY_GCC_HAS_ATTRIBUTE(format,4,4,0) && !defined(__USE_MINGW_ANSI_STDIO)
#define JSON_HEDLEY_PRINTF_FORMAT(string_idx,first_to_check) __attribute__((__format__(ms_printf, string_idx, first_to_check)))
#elif defined(__MINGW32__) && JSON_HEDLEY_GCC_HAS_ATTRIBUTE(format,4,4,0) && defined(__USE_MINGW_ANSI_STDIO)
#define JSON_HEDLEY_PRINTF_FORMAT(string_idx,first_to_check) __attribute__((__format__(gnu_printf, string_idx, first_to_check)))
#elif \
    JSON_HEDLEY_HAS_ATTRIBUTE(format) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(3,1,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(5,6,0) || \
    JSON_HEDLEY_IBM_VERSION_CHECK(10,1,0) || \
    JSON_HEDLEY_TI_VERSION_CHECK(8,0,0) || \
    (JSON_HEDLEY_TI_VERSION_CHECK(7,3,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__))
#define JSON_HEDLEY_PRINTF_FORMAT(string_idx,first_to_check) __attribute__((__format__(__printf__, string_idx, first_to_check)))
#elif JSON_HEDLEY_PELLES_VERSION_CHECK(6,0,0)
#define JSON_HEDLEY_PRINTF_FORMAT(string_idx,first_to_check) __declspec(vaformat(printf,string_idx,first_to_check))
#else
#define JSON_HEDLEY_PRINTF_FORMAT(string_idx,first_to_check)
#endif

#if defined(JSON_HEDLEY_CONSTEXPR)
#undef JSON_HEDLEY_CONSTEXPR
#endif
#if defined(__cplusplus)
#if __cplusplus >= 201103L
#define JSON_HEDLEY_CONSTEXPR constexpr
#endif
#endif
#if !defined(JSON_HEDLEY_CONSTEXPR)
#define JSON_HEDLEY_CONSTEXPR
#endif

#if defined(JSON_HEDLEY_PREDICT)
#undef JSON_HEDLEY_PREDICT
#endif
#if defined(JSON_HEDLEY_LIKELY)
#undef JSON_HEDLEY_LIKELY
#endif
#if defined(JSON_HEDLEY_UNLIKELY)
#undef JSON_HEDLEY_UNLIKELY
#endif
#if defined(JSON_HEDLEY_UNPREDICTABLE)
#undef JSON_HEDLEY_UNPREDICTABLE
#endif
#if JSON_HEDLEY_HAS_BUILTIN(__builtin_unpredictable)
#define JSON_HEDLEY_UNPREDICTABLE(expr) __builtin_unpredictable(!!(expr))
#endif
#if \
  JSON_HEDLEY_HAS_BUILTIN(__builtin_expect_with_probability) || \
  JSON_HEDLEY_GCC_VERSION_CHECK(9,0,0)
#  define JSON_HEDLEY_PREDICT(expr, value, probability) __builtin_expect_with_probability(expr, value, probability)
#  define JSON_HEDLEY_PREDICT_TRUE(expr, probability) __builtin_expect_with_probability(!!(expr), 1, probability)
#  define JSON_HEDLEY_PREDICT_FALSE(expr, probability) __builtin_expect_with_probability(!!(expr), 0, probability)
#  define JSON_HEDLEY_LIKELY(expr) __builtin_expect(!!(expr), 1)
#  define JSON_HEDLEY_UNLIKELY(expr) __builtin_expect(!!(expr), 0)
#if !defined(JSON_HEDLEY_BUILTIN_UNPREDICTABLE)
#define JSON_HEDLEY_BUILTIN_UNPREDICTABLE(expr) __builtin_expect_with_probability(!!(expr), 1, 0.5)
#endif
#elif \
  JSON_HEDLEY_HAS_BUILTIN(__builtin_expect) || \
  JSON_HEDLEY_GCC_VERSION_CHECK(3,0,0) || \
  JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
  (JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,15,0) && defined(__cplusplus)) || \
  JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
  JSON_HEDLEY_IBM_VERSION_CHECK(10,1,0) || \
  JSON_HEDLEY_TI_VERSION_CHECK(6,1,0) || \
  JSON_HEDLEY_TINYC_VERSION_CHECK(0,9,27)
#  define JSON_HEDLEY_PREDICT(expr, expected, probability) \
    (((probability) >= 0.9) ? __builtin_expect(!!(expr), (expected)) : (((void) (expected)), !!(expr)))
#  define JSON_HEDLEY_PREDICT_TRUE(expr, probability) \
    (__extension__ ({ \
        JSON_HEDLEY_CONSTEXPR double hedley_probability_ = (probability); \
        ((hedley_probability_ >= 0.9) ? __builtin_expect(!!(expr), 1) : ((hedley_probability_ <= 0.1) ? __builtin_expect(!!(expr), 0) : !!(expr))); \
    }))
#  define JSON_HEDLEY_PREDICT_FALSE(expr, probability) \
    (__extension__ ({ \
        JSON_HEDLEY_CONSTEXPR double hedley_probability_ = (probability); \
        ((hedley_probability_ >= 0.9) ? __builtin_expect(!!(expr), 0) : ((hedley_probability_ <= 0.1) ? __builtin_expect(!!(expr), 1) : !!(expr))); \
    }))
#  define JSON_HEDLEY_LIKELY(expr)   __builtin_expect(!!(expr), 1)
#  define JSON_HEDLEY_UNLIKELY(expr) __builtin_expect(!!(expr), 0)
#else
#  define JSON_HEDLEY_PREDICT(expr, expected, probability) (((void) (expected)), !!(expr))
#  define JSON_HEDLEY_PREDICT_TRUE(expr, probability) (!!(expr))
#  define JSON_HEDLEY_PREDICT_FALSE(expr, probability) (!!(expr))
#  define JSON_HEDLEY_LIKELY(expr) (!!(expr))
#  define JSON_HEDLEY_UNLIKELY(expr) (!!(expr))
#endif
#if !defined(JSON_HEDLEY_UNPREDICTABLE)
#define JSON_HEDLEY_UNPREDICTABLE(expr) JSON_HEDLEY_PREDICT(expr, 1, 0.5)
#endif

#if defined(JSON_HEDLEY_MALLOC)
#undef JSON_HEDLEY_MALLOC
#endif
#if \
    JSON_HEDLEY_HAS_ATTRIBUTE(malloc) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(3,1,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,11,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
    JSON_HEDLEY_IBM_VERSION_CHECK(12,1,0) || \
    JSON_HEDLEY_TI_VERSION_CHECK(8,0,0) || \
    (JSON_HEDLEY_TI_VERSION_CHECK(7,3,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__))
#define JSON_HEDLEY_MALLOC __attribute__((__malloc__))
#elif JSON_HEDLEY_MSVC_VERSION_CHECK(14, 0, 0)
#define JSON_HEDLEY_MALLOC __declspec(restrict)
#else
#define JSON_HEDLEY_MALLOC
#endif

#if defined(JSON_HEDLEY_PURE)
#undef JSON_HEDLEY_PURE
#endif
#if \
    JSON_HEDLEY_HAS_ATTRIBUTE(pure) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(2,96,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,11,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
    JSON_HEDLEY_IBM_VERSION_CHECK(10,1,0) || \
    JSON_HEDLEY_TI_VERSION_CHECK(8,0,0) || \
    (JSON_HEDLEY_TI_VERSION_CHECK(7,3,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_PGI_VERSION_CHECK(17,10,0)
#define JSON_HEDLEY_PURE __attribute__((__pure__))
#elif JSON_HEDLEY_TI_VERSION_CHECK(6,0,0) && defined(__cplusplus)
#define JSON_HEDLEY_PURE _Pragma("FUNC_IS_PURE;")
#else
#define JSON_HEDLEY_PURE
#endif

#if defined(JSON_HEDLEY_CONST)
#undef JSON_HEDLEY_CONST
#endif
#if \
    JSON_HEDLEY_HAS_ATTRIBUTE(const) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(2,5,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,11,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
    JSON_HEDLEY_IBM_VERSION_CHECK(10,1,0) || \
    JSON_HEDLEY_TI_VERSION_CHECK(8,0,0) || \
    (JSON_HEDLEY_TI_VERSION_CHECK(7,3,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_PGI_VERSION_CHECK(17,10,0)
#define JSON_HEDLEY_CONST __attribute__((__const__))
#else
#define JSON_HEDLEY_CONST JSON_HEDLEY_PURE
#endif

#if defined(JSON_HEDLEY_RESTRICT)
#undef JSON_HEDLEY_RESTRICT
#endif
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L) && !defined(__cplusplus)
#define JSON_HEDLEY_RESTRICT restrict
#elif \
    JSON_HEDLEY_GCC_VERSION_CHECK(3,1,0) || \
    JSON_HEDLEY_MSVC_VERSION_CHECK(14,0,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
    JSON_HEDLEY_IBM_VERSION_CHECK(10,1,0) || \
    JSON_HEDLEY_PGI_VERSION_CHECK(17,10,0) || \
    JSON_HEDLEY_TI_VERSION_CHECK(8,0,0) || \
    (JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,14,0) && defined(__cplusplus)) || \
    JSON_HEDLEY_IAR_VERSION_CHECK(8,0,0) || \
    defined(__clang__)
#define JSON_HEDLEY_RESTRICT __restrict
#elif JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,3,0) && !defined(__cplusplus)
#define JSON_HEDLEY_RESTRICT _Restrict
#else
#define JSON_HEDLEY_RESTRICT
#endif

#if defined(JSON_HEDLEY_INLINE)
#undef JSON_HEDLEY_INLINE
#endif
#if \
    (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)) || \
    (defined(__cplusplus) && (__cplusplus >= 199711L))
#define JSON_HEDLEY_INLINE inline
#elif \
    defined(JSON_HEDLEY_GCC_VERSION) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(6,2,0)
#define JSON_HEDLEY_INLINE __inline__
#elif \
    JSON_HEDLEY_MSVC_VERSION_CHECK(12,0,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
    JSON_HEDLEY_TI_VERSION_CHECK(8,0,0)
#define JSON_HEDLEY_INLINE __inline
#else
#define JSON_HEDLEY_INLINE
#endif

#if defined(JSON_HEDLEY_ALWAYS_INLINE)
#undef JSON_HEDLEY_ALWAYS_INLINE
#endif
#if \
    JSON_HEDLEY_HAS_ATTRIBUTE(always_inline) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(4,0,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,11,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
    JSON_HEDLEY_IBM_VERSION_CHECK(10,1,0) || \
    JSON_HEDLEY_TI_VERSION_CHECK(8,0,0) || \
    (JSON_HEDLEY_TI_VERSION_CHECK(7,3,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__))
#define JSON_HEDLEY_ALWAYS_INLINE __attribute__((__always_inline__)) JSON_HEDLEY_INLINE
#elif JSON_HEDLEY_MSVC_VERSION_CHECK(12,0,0)
#define JSON_HEDLEY_ALWAYS_INLINE __forceinline
#elif JSON_HEDLEY_TI_VERSION_CHECK(7,0,0) && defined(__cplusplus)
#define JSON_HEDLEY_ALWAYS_INLINE _Pragma("FUNC_ALWAYS_INLINE;")
#elif JSON_HEDLEY_IAR_VERSION_CHECK(8,0,0)
#define JSON_HEDLEY_ALWAYS_INLINE _Pragma("inline=forced")
#else
#define JSON_HEDLEY_ALWAYS_INLINE JSON_HEDLEY_INLINE
#endif

#if defined(JSON_HEDLEY_NEVER_INLINE)
#undef JSON_HEDLEY_NEVER_INLINE
#endif
#if \
    JSON_HEDLEY_HAS_ATTRIBUTE(noinline) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(4,0,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,11,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
    JSON_HEDLEY_IBM_VERSION_CHECK(10,1,0) || \
    JSON_HEDLEY_TI_VERSION_CHECK(8,0,0) || \
    (JSON_HEDLEY_TI_VERSION_CHECK(7,3,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__))
#define JSON_HEDLEY_NEVER_INLINE __attribute__((__noinline__))
#elif JSON_HEDLEY_MSVC_VERSION_CHECK(13,10,0)
#define JSON_HEDLEY_NEVER_INLINE __declspec(noinline)
#elif JSON_HEDLEY_PGI_VERSION_CHECK(10,2,0)
#define JSON_HEDLEY_NEVER_INLINE _Pragma("noinline")
#elif JSON_HEDLEY_TI_VERSION_CHECK(6,0,0) && defined(__cplusplus)
#define JSON_HEDLEY_NEVER_INLINE _Pragma("FUNC_CANNOT_INLINE;")
#elif JSON_HEDLEY_IAR_VERSION_CHECK(8,0,0)
#define JSON_HEDLEY_NEVER_INLINE _Pragma("inline=never")
#elif JSON_HEDLEY_COMPCERT_VERSION_CHECK(3,2,0)
#define JSON_HEDLEY_NEVER_INLINE __attribute((noinline))
#elif JSON_HEDLEY_PELLES_VERSION_CHECK(9,0,0)
#define JSON_HEDLEY_NEVER_INLINE __declspec(noinline)
#else
#define JSON_HEDLEY_NEVER_INLINE
#endif

#if defined(JSON_HEDLEY_PRIVATE)
#undef JSON_HEDLEY_PRIVATE
#endif
#if defined(JSON_HEDLEY_PUBLIC)
#undef JSON_HEDLEY_PUBLIC
#endif
#if defined(JSON_HEDLEY_IMPORT)
#undef JSON_HEDLEY_IMPORT
#endif
#if defined(_WIN32) || defined(__CYGWIN__)
#define JSON_HEDLEY_PRIVATE
#define JSON_HEDLEY_PUBLIC   __declspec(dllexport)
#define JSON_HEDLEY_IMPORT   __declspec(dllimport)
#else
#if \
        JSON_HEDLEY_HAS_ATTRIBUTE(visibility) || \
        JSON_HEDLEY_GCC_VERSION_CHECK(3,3,0) || \
        JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,11,0) || \
        JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
        JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
        JSON_HEDLEY_IBM_VERSION_CHECK(13,1,0) || \
        JSON_HEDLEY_TI_VERSION_CHECK(8,0,0) || \
        (JSON_HEDLEY_TI_VERSION_CHECK(7,3,0) && defined(__TI_EABI__) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__))
#define JSON_HEDLEY_PRIVATE __attribute__((__visibility__("hidden")))
#define JSON_HEDLEY_PUBLIC  __attribute__((__visibility__("default")))
#else
#define JSON_HEDLEY_PRIVATE
#define JSON_HEDLEY_PUBLIC
#endif
#define JSON_HEDLEY_IMPORT    extern
#endif

#if defined(JSON_HEDLEY_NO_THROW)
#undef JSON_HEDLEY_NO_THROW
#endif
#if \
    JSON_HEDLEY_HAS_ATTRIBUTE(nothrow) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(3,3,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0)
#define JSON_HEDLEY_NO_THROW __attribute__((__nothrow__))
#elif \
    JSON_HEDLEY_MSVC_VERSION_CHECK(13,1,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0)
#define JSON_HEDLEY_NO_THROW __declspec(nothrow)
#else
#define JSON_HEDLEY_NO_THROW
#endif

#if defined(JSON_HEDLEY_FALL_THROUGH)
#undef JSON_HEDLEY_FALL_THROUGH
#endif
#if \
    defined(__cplusplus) && \
    (!defined(JSON_HEDLEY_SUNPRO_VERSION) || JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,15,0)) && \
    !defined(JSON_HEDLEY_PGI_VERSION)
#if \
        (__cplusplus >= 201703L) || \
        ((__cplusplus >= 201103L) && JSON_HEDLEY_HAS_CPP_ATTRIBUTE(fallthrough))
#define JSON_HEDLEY_FALL_THROUGH [[fallthrough]]
#elif (__cplusplus >= 201103L) && JSON_HEDLEY_HAS_CPP_ATTRIBUTE(clang::fallthrough)
#define JSON_HEDLEY_FALL_THROUGH [[clang::fallthrough]]
#elif (__cplusplus >= 201103L) && JSON_HEDLEY_GCC_VERSION_CHECK(7,0,0)
#define JSON_HEDLEY_FALL_THROUGH [[gnu::fallthrough]]
#endif
#endif
#if !defined(JSON_HEDLEY_FALL_THROUGH)
#if JSON_HEDLEY_GNUC_HAS_ATTRIBUTE(fallthrough,7,0,0) && !defined(JSON_HEDLEY_PGI_VERSION)
#define JSON_HEDLEY_FALL_THROUGH __attribute__((__fallthrough__))
#elif defined(__fallthrough) /* SAL */
#define JSON_HEDLEY_FALL_THROUGH __fallthrough
#else
#define JSON_HEDLEY_FALL_THROUGH
#endif
#endif

#if defined(JSON_HEDLEY_RETURNS_NON_NULL)
#undef JSON_HEDLEY_RETURNS_NON_NULL
#endif
#if \
    JSON_HEDLEY_HAS_ATTRIBUTE(returns_nonnull) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(4,9,0)
#define JSON_HEDLEY_RETURNS_NON_NULL __attribute__((__returns_nonnull__))
#elif defined(_Ret_notnull_) /* SAL */
#define JSON_HEDLEY_RETURNS_NON_NULL _Ret_notnull_
#else
#define JSON_HEDLEY_RETURNS_NON_NULL
#endif

#if defined(JSON_HEDLEY_ARRAY_PARAM)
#undef JSON_HEDLEY_ARRAY_PARAM
#endif
#if \
    defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L) && \
    !defined(__STDC_NO_VLA__) && \
    !defined(__cplusplus) && \
    !defined(JSON_HEDLEY_PGI_VERSION) && \
    !defined(JSON_HEDLEY_TINYC_VERSION)
#define JSON_HEDLEY_ARRAY_PARAM(name) (name)
#else
#define JSON_HEDLEY_ARRAY_PARAM(name)
#endif

#if defined(JSON_HEDLEY_IS_CONSTANT)
#undef JSON_HEDLEY_IS_CONSTANT
#endif
#if defined(JSON_HEDLEY_REQUIRE_CONSTEXPR)
#undef JSON_HEDLEY_REQUIRE_CONSTEXPR
#endif
/* Note the double-underscore. For internal use only; no API
 * guarantees! */
#if defined(JSON_HEDLEY__IS_CONSTEXPR)
#undef JSON_HEDLEY__IS_CONSTEXPR
#endif

#if \
    JSON_HEDLEY_HAS_BUILTIN(__builtin_constant_p) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(3,4,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_TINYC_VERSION_CHECK(0,9,19) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
    JSON_HEDLEY_IBM_VERSION_CHECK(13,1,0) || \
    JSON_HEDLEY_TI_VERSION_CHECK(6,1,0) || \
    JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,10,0) || \
    JSON_HEDLEY_CRAY_VERSION_CHECK(8,1,0)
#define JSON_HEDLEY_IS_CONSTANT(expr) __builtin_constant_p(expr)
#endif
#if !defined(__cplusplus)
#  if \
       JSON_HEDLEY_HAS_BUILTIN(__builtin_types_compatible_p) || \
       JSON_HEDLEY_GCC_VERSION_CHECK(3,4,0) || \
       JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
       JSON_HEDLEY_IBM_VERSION_CHECK(13,1,0) || \
       JSON_HEDLEY_CRAY_VERSION_CHECK(8,1,0) || \
       JSON_HEDLEY_ARM_VERSION_CHECK(5,4,0) || \
       JSON_HEDLEY_TINYC_VERSION_CHECK(0,9,24)
#if defined(__INTPTR_TYPE__)
#define JSON_HEDLEY__IS_CONSTEXPR(expr) __builtin_types_compatible_p(__typeof__((1 ? (void*) ((__INTPTR_TYPE__) ((expr) * 0)) : (int*) 0)), int*)
#else
#include <stdint.h>
#define JSON_HEDLEY__IS_CONSTEXPR(expr) __builtin_types_compatible_p(__typeof__((1 ? (void*) ((intptr_t) ((expr) * 0)) : (int*) 0)), int*)
#endif
#  elif \
       (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L) && !defined(JSON_HEDLEY_SUNPRO_VERSION) && !defined(JSON_HEDLEY_PGI_VERSION)) || \
       JSON_HEDLEY_HAS_EXTENSION(c_generic_selections) || \
       JSON_HEDLEY_GCC_VERSION_CHECK(4,9,0) || \
       JSON_HEDLEY_INTEL_VERSION_CHECK(17,0,0) || \
       JSON_HEDLEY_IBM_VERSION_CHECK(12,1,0) || \
       JSON_HEDLEY_ARM_VERSION_CHECK(5,3,0)
#if defined(__INTPTR_TYPE__)
#define JSON_HEDLEY__IS_CONSTEXPR(expr) _Generic((1 ? (void*) ((__INTPTR_TYPE__) ((expr) * 0)) : (int*) 0), int*: 1, void*: 0)
#else
#include <stdint.h>
#define JSON_HEDLEY__IS_CONSTEXPR(expr) _Generic((1 ? (void*) ((intptr_t) * 0) : (int*) 0), int*: 1, void*: 0)
#endif
#  elif \
       defined(JSON_HEDLEY_GCC_VERSION) || \
       defined(JSON_HEDLEY_INTEL_VERSION) || \
       defined(JSON_HEDLEY_TINYC_VERSION) || \
       defined(JSON_HEDLEY_TI_VERSION) || \
       defined(__clang__)
#    define JSON_HEDLEY__IS_CONSTEXPR(expr) ( \
        sizeof(void) != \
        sizeof(*( \
                  1 ? \
                  ((void*) ((expr) * 0L) ) : \
((struct { char v[sizeof(void) * 2]; } *) 1) \
                ) \
              ) \
                                            )
#  endif
#endif
#if defined(JSON_HEDLEY__IS_CONSTEXPR)
#if !defined(JSON_HEDLEY_IS_CONSTANT)
#define JSON_HEDLEY_IS_CONSTANT(expr) JSON_HEDLEY__IS_CONSTEXPR(expr)
#endif
#define JSON_HEDLEY_REQUIRE_CONSTEXPR(expr) (JSON_HEDLEY__IS_CONSTEXPR(expr) ? (expr) : (-1))
#else
#if !defined(JSON_HEDLEY_IS_CONSTANT)
#define JSON_HEDLEY_IS_CONSTANT(expr) (0)
#endif
#define JSON_HEDLEY_REQUIRE_CONSTEXPR(expr) (expr)
#endif

#if defined(JSON_HEDLEY_BEGIN_C_DECLS)
#undef JSON_HEDLEY_BEGIN_C_DECLS
#endif
#if defined(JSON_HEDLEY_END_C_DECLS)
#undef JSON_HEDLEY_END_C_DECLS
#endif
#if defined(JSON_HEDLEY_C_DECL)
#undef JSON_HEDLEY_C_DECL
#endif
#if defined(__cplusplus)
#define JSON_HEDLEY_BEGIN_C_DECLS extern "C" {
#define JSON_HEDLEY_END_C_DECLS }
#define JSON_HEDLEY_C_DECL extern "C"
#else
#define JSON_HEDLEY_BEGIN_C_DECLS
#define JSON_HEDLEY_END_C_DECLS
#define JSON_HEDLEY_C_DECL
#endif

#if defined(JSON_HEDLEY_STATIC_ASSERT)
#undef JSON_HEDLEY_STATIC_ASSERT
#endif
#if \
  !defined(__cplusplus) && ( \
      (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)) || \
      JSON_HEDLEY_HAS_FEATURE(c_static_assert) || \
      JSON_HEDLEY_GCC_VERSION_CHECK(6,0,0) || \
      JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
      defined(_Static_assert) \
    )
#  define JSON_HEDLEY_STATIC_ASSERT(expr, message) _Static_assert(expr, message)
#elif \
  (defined(__cplusplus) && (__cplusplus >= 201703L)) || \
  JSON_HEDLEY_MSVC_VERSION_CHECK(16,0,0) || \
  (defined(__cplusplus) && JSON_HEDLEY_TI_VERSION_CHECK(8,3,0))
#  define JSON_HEDLEY_STATIC_ASSERT(expr, message) static_assert(expr, message)
#elif defined(__cplusplus) && (__cplusplus >= 201103L)
#  define JSON_HEDLEY_STATIC_ASSERT(expr, message) static_assert(expr)
#else
#  define JSON_HEDLEY_STATIC_ASSERT(expr, message)
#endif

#if defined(JSON_HEDLEY_CONST_CAST)
#undef JSON_HEDLEY_CONST_CAST
#endif
#if defined(__cplusplus)
#  define JSON_HEDLEY_CONST_CAST(T, expr) (const_cast<T>(expr))
#elif \
  JSON_HEDLEY_HAS_WARNING("-Wcast-qual") || \
  JSON_HEDLEY_GCC_VERSION_CHECK(4,6,0) || \
  JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0)
#  define JSON_HEDLEY_CONST_CAST(T, expr) (__extension__ ({ \
        JSON_HEDLEY_DIAGNOSTIC_PUSH \
        JSON_HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL \
        ((T) (expr)); \
        JSON_HEDLEY_DIAGNOSTIC_POP \
    }))
#else
#  define JSON_HEDLEY_CONST_CAST(T, expr) ((T) (expr))
#endif

#if defined(JSON_HEDLEY_REINTERPRET_CAST)
#undef JSON_HEDLEY_REINTERPRET_CAST
#endif
#if defined(__cplusplus)
#define JSON_HEDLEY_REINTERPRET_CAST(T, expr) (reinterpret_cast<T>(expr))
#else
#define JSON_HEDLEY_REINTERPRET_CAST(T, expr) (*((T*) &(expr)))
#endif

#if defined(JSON_HEDLEY_STATIC_CAST)
#undef JSON_HEDLEY_STATIC_CAST
#endif
#if defined(__cplusplus)
#define JSON_HEDLEY_STATIC_CAST(T, expr) (static_cast<T>(expr))
#else
#define JSON_HEDLEY_STATIC_CAST(T, expr) ((T) (expr))
#endif

#if defined(JSON_HEDLEY_CPP_CAST)
#undef JSON_HEDLEY_CPP_CAST
#endif
#if defined(__cplusplus)
#define JSON_HEDLEY_CPP_CAST(T, expr) static_cast<T>(expr)
#else
#define JSON_HEDLEY_CPP_CAST(T, expr) (expr)
#endif

#if defined(JSON_HEDLEY_MESSAGE)
#undef JSON_HEDLEY_MESSAGE
#endif
#if JSON_HEDLEY_HAS_WARNING("-Wunknown-pragmas")
#  define JSON_HEDLEY_MESSAGE(msg) \
    JSON_HEDLEY_DIAGNOSTIC_PUSH \
    JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS \
    JSON_HEDLEY_PRAGMA(message msg) \
    JSON_HEDLEY_DIAGNOSTIC_POP
#elif \
  JSON_HEDLEY_GCC_VERSION_CHECK(4,4,0) || \
  JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0)
#  define JSON_HEDLEY_MESSAGE(msg) JSON_HEDLEY_PRAGMA(message msg)
#elif JSON_HEDLEY_CRAY_VERSION_CHECK(5,0,0)
#  define JSON_HEDLEY_MESSAGE(msg) JSON_HEDLEY_PRAGMA(_CRI message msg)
#elif JSON_HEDLEY_IAR_VERSION_CHECK(8,0,0)
#  define JSON_HEDLEY_MESSAGE(msg) JSON_HEDLEY_PRAGMA(message(msg))
#elif JSON_HEDLEY_PELLES_VERSION_CHECK(2,0,0)
#  define JSON_HEDLEY_MESSAGE(msg) JSON_HEDLEY_PRAGMA(message(msg))
#else
#  define JSON_HEDLEY_MESSAGE(msg)
#endif

#if defined(JSON_HEDLEY_WARNING)
#undef JSON_HEDLEY_WARNING
#endif
#if JSON_HEDLEY_HAS_WARNING("-Wunknown-pragmas")
#  define JSON_HEDLEY_WARNING(msg) \
    JSON_HEDLEY_DIAGNOSTIC_PUSH \
    JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS \
    JSON_HEDLEY_PRAGMA(clang warning msg) \
    JSON_HEDLEY_DIAGNOSTIC_POP
#elif \
  JSON_HEDLEY_GCC_VERSION_CHECK(4,8,0) || \
  JSON_HEDLEY_PGI_VERSION_CHECK(18,4,0)
#  define JSON_HEDLEY_WARNING(msg) JSON_HEDLEY_PRAGMA(GCC warning msg)
#elif JSON_HEDLEY_MSVC_VERSION_CHECK(15,0,0)
#  define JSON_HEDLEY_WARNING(msg) JSON_HEDLEY_PRAGMA(message(msg))
#else
#  define JSON_HEDLEY_WARNING(msg) JSON_HEDLEY_MESSAGE(msg)
#endif

#if defined(JSON_HEDLEY_REQUIRE_MSG)
#undef JSON_HEDLEY_REQUIRE_MSG
#endif
#if JSON_HEDLEY_HAS_ATTRIBUTE(diagnose_if)
#  if JSON_HEDLEY_HAS_WARNING("-Wgcc-compat")
#    define JSON_HEDLEY_REQUIRE_MSG(expr, msg) \
    JSON_HEDLEY_DIAGNOSTIC_PUSH \
    _Pragma("clang diagnostic ignored \"-Wgcc-compat\"") \
    __attribute__((__diagnose_if__(!(expr), msg, "error"))) \
    JSON_HEDLEY_DIAGNOSTIC_POP
#  else
#    define JSON_HEDLEY_REQUIRE_MSG(expr, msg) __attribute__((__diagnose_if__(!(expr), msg, "error")))
#  endif
#else
#  define JSON_HEDLEY_REQUIRE_MSG(expr, msg)
#endif

#if defined(JSON_HEDLEY_REQUIRE)
#undef JSON_HEDLEY_REQUIRE
#endif
#define JSON_HEDLEY_REQUIRE(expr) JSON_HEDLEY_REQUIRE_MSG(expr, #expr)

#if defined(JSON_HEDLEY_FLAGS)
#undef JSON_HEDLEY_FLAGS
#endif
#if JSON_HEDLEY_HAS_ATTRIBUTE(flag_enum)
#define JSON_HEDLEY_FLAGS __attribute__((__flag_enum__))
#endif

#if defined(JSON_HEDLEY_FLAGS_CAST)
#undef JSON_HEDLEY_FLAGS_CAST
#endif
#if JSON_HEDLEY_INTEL_VERSION_CHECK(19,0,0)
#  define JSON_HEDLEY_FLAGS_CAST(T, expr) (__extension__ ({ \
        JSON_HEDLEY_DIAGNOSTIC_PUSH \
        _Pragma("warning(disable:188)") \
        ((T) (expr)); \
        JSON_HEDLEY_DIAGNOSTIC_POP \
    }))
#else
#  define JSON_HEDLEY_FLAGS_CAST(T, expr) JSON_HEDLEY_STATIC_CAST(T, expr)
#endif

 /* Remaining macros are deprecated. */

#if defined(JSON_HEDLEY_GCC_NOT_CLANG_VERSION_CHECK)
#undef JSON_HEDLEY_GCC_NOT_CLANG_VERSION_CHECK
#endif
#if defined(__clang__)
#define JSON_HEDLEY_GCC_NOT_CLANG_VERSION_CHECK(major,minor,patch) (0)
#else
#define JSON_HEDLEY_GCC_NOT_CLANG_VERSION_CHECK(major,minor,patch) JSON_HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(JSON_HEDLEY_CLANG_HAS_ATTRIBUTE)
#undef JSON_HEDLEY_CLANG_HAS_ATTRIBUTE
#endif
#define JSON_HEDLEY_CLANG_HAS_ATTRIBUTE(attribute) JSON_HEDLEY_HAS_ATTRIBUTE(attribute)

#if defined(JSON_HEDLEY_CLANG_HAS_CPP_ATTRIBUTE)
#undef JSON_HEDLEY_CLANG_HAS_CPP_ATTRIBUTE
#endif
#define JSON_HEDLEY_CLANG_HAS_CPP_ATTRIBUTE(attribute) JSON_HEDLEY_HAS_CPP_ATTRIBUTE(attribute)

#if defined(JSON_HEDLEY_CLANG_HAS_BUILTIN)
#undef JSON_HEDLEY_CLANG_HAS_BUILTIN
#endif
#define JSON_HEDLEY_CLANG_HAS_BUILTIN(builtin) JSON_HEDLEY_HAS_BUILTIN(builtin)

#if defined(JSON_HEDLEY_CLANG_HAS_FEATURE)
#undef JSON_HEDLEY_CLANG_HAS_FEATURE
#endif
#define JSON_HEDLEY_CLANG_HAS_FEATURE(feature) JSON_HEDLEY_HAS_FEATURE(feature)

#if defined(JSON_HEDLEY_CLANG_HAS_EXTENSION)
#undef JSON_HEDLEY_CLANG_HAS_EXTENSION
#endif
#define JSON_HEDLEY_CLANG_HAS_EXTENSION(extension) JSON_HEDLEY_HAS_EXTENSION(extension)

#if defined(JSON_HEDLEY_CLANG_HAS_DECLSPEC_DECLSPEC_ATTRIBUTE)
#undef JSON_HEDLEY_CLANG_HAS_DECLSPEC_DECLSPEC_ATTRIBUTE
#endif
#define JSON_HEDLEY_CLANG_HAS_DECLSPEC_ATTRIBUTE(attribute) JSON_HEDLEY_HAS_DECLSPEC_ATTRIBUTE(attribute)

#if defined(JSON_HEDLEY_CLANG_HAS_WARNING)
#undef JSON_HEDLEY_CLANG_HAS_WARNING
#endif
#define JSON_HEDLEY_CLANG_HAS_WARNING(warning) JSON_HEDLEY_HAS_WARNING(warning)

#endif /* !defined(JSON_HEDLEY_VERSION) || (JSON_HEDLEY_VERSION < X) */


// This file contains all internal macro definitions
// You MUST include macro_unscope.hpp at the end of json.hpp to undef all of them

// exclude unsupported compilers
#if !defined(JSON_SKIP_UNSUPPORTED_COMPILER_CHECK)
#if defined(__clang__)
#if (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__) < 30400
#error "unsupported Clang version - see https://github.com/nlohmann/json#supported-compilers"
#endif
#elif defined(__GNUC__) && !(defined(__ICC) || defined(__INTEL_COMPILER))
#if (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__) < 40800
#error "unsupported GCC version - see https://github.com/nlohmann/json#supported-compilers"
#endif
#endif
#endif

// C++ language standard detection
#if (defined(__cplusplus) && __cplusplus >= 201703L) || (defined(_HAS_CXX17) && _HAS_CXX17 == 1) // fix for issue #464
#define JSON_HAS_CPP_17
#define JSON_HAS_CPP_14
#elif (defined(__cplusplus) && __cplusplus >= 201402L) || (defined(_HAS_CXX14) && _HAS_CXX14 == 1)
#define JSON_HAS_CPP_14
#endif

// disable float-equal warnings on GCC/clang
#if defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
#endif

// disable documentation warnings on clang
#if defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdocumentation"
#endif

// allow to disable exceptions
#if (defined(__cpp_exceptions) || defined(__EXCEPTIONS) || defined(_CPPUNWIND)) && !defined(JSON_NOEXCEPTION)
#define JSON_THROW(exception) throw exception
#define JSON_TRY try
#define JSON_CATCH(exception) catch(exception)
#define JSON_INTERNAL_CATCH(exception) catch(exception)
#else
#include <cstdlib>
#define JSON_THROW(exception) std::abort()
#define JSON_TRY if(true)
#define JSON_CATCH(exception) if(false)
#define JSON_INTERNAL_CATCH(exception) if(false)
#endif

// override exception macros
#if defined(JSON_THROW_USER)
#undef JSON_THROW
#define JSON_THROW JSON_THROW_USER
#endif
#if defined(JSON_TRY_USER)
#undef JSON_TRY
#define JSON_TRY JSON_TRY_USER
#endif
#if defined(JSON_CATCH_USER)
#undef JSON_CATCH
#define JSON_CATCH JSON_CATCH_USER
#undef JSON_INTERNAL_CATCH
#define JSON_INTERNAL_CATCH JSON_CATCH_USER
#endif
#if defined(JSON_INTERNAL_CATCH_USER)
#undef JSON_INTERNAL_CATCH
#define JSON_INTERNAL_CATCH JSON_INTERNAL_CATCH_USER
#endif

/*!
@brief macro to briefly define a mapping between an enum and JSON
@def NLOHMANN_JSON_SERIALIZE_ENUM
@since version 3.4.0
*/
#define NLOHMANN_JSON_SERIALIZE_ENUM(ENUM_TYPE, ...)                                           \
    template<typename BasicJsonType>                                                           \
    inline void to_json(BasicJsonType& j, const ENUM_TYPE& e)                                  \
    {                                                                                          \
        static_assert(std::is_enum<ENUM_TYPE>::value, #ENUM_TYPE " must be an enum!");         \
        static const std::pair<ENUM_TYPE, BasicJsonType> m[] = __VA_ARGS__;                    \
        auto it = std::find_if(std::begin(m), std::end(m),                                     \
                               [e](const std::pair<ENUM_TYPE, BasicJsonType>& ej_pair) -> bool \
        {                                                                                      \
            return ej_pair.first == e;                                                         \
        });                                                                                    \
        j = ((it != std::end(m)) ? it : std::begin(m))->second;                                \
    }                                                                                          \
    template<typename BasicJsonType>                                                           \
    inline void from_json(const BasicJsonType& j, ENUM_TYPE& e)                                \
    {                                                                                          \
        static_assert(std::is_enum<ENUM_TYPE>::value, #ENUM_TYPE " must be an enum!");         \
        static const std::pair<ENUM_TYPE, BasicJsonType> m[] = __VA_ARGS__;                    \
        auto it = std::find_if(std::begin(m), std::end(m),                                     \
                               [j](const std::pair<ENUM_TYPE, BasicJsonType>& ej_pair) -> bool \
        {                                                                                      \
            return ej_pair.second == j;                                                        \
        });                                                                                    \
        e = ((it != std::end(m)) ? it : std::begin(m))->first;                                 \
    }

// Ugly macros to avoid uglier copy-paste when specializing basic_json. They
// may be removed in the future once the class is split.

#define NLOHMANN_BASIC_JSON_TPL_DECLARATION                                \
    template<template<typename, typename, typename...> class ObjectType,   \
             template<typename, typename...> class ArrayType,              \
             class StringType, class BooleanType, class NumberIntegerType, \
             class NumberUnsignedType, class NumberFloatType,              \
             template<typename> class AllocatorType,                       \
             template<typename, typename = void> class JSONSerializer>

#define NLOHMANN_BASIC_JSON_TPL                                            \
    basic_json<ObjectType, ArrayType, StringType, BooleanType,             \
    NumberIntegerType, NumberUnsignedType, NumberFloatType,                \
    AllocatorType, JSONSerializer>


namespace nlohmann
{
	namespace detail
	{
		////////////////
		// exceptions //
		////////////////

		/*!
		@brief general exception of the @ref basic_json class
		This class is an extension of `std::exception` objects with a member @a id for
		exception ids. It is used as the base class for all exceptions thrown by the
		@ref basic_json class. This class can hence be used as "wildcard" to catch
		exceptions.
		Subclasses:
		- @ref parse_error for exceptions indicating a parse error
		- @ref invalid_iterator for exceptions indicating errors with iterators
		- @ref type_error for exceptions indicating executing a member function with
						  a wrong type
		- @ref out_of_range for exceptions indicating access out of the defined range
		- @ref other_error for exceptions indicating other library errors
		@internal
		@note To have nothrow-copy-constructible exceptions, we internally use
			  `std::runtime_error` which can cope with arbitrary-length error messages.
			  Intermediate strings are built with static functions and then passed to
			  the actual constructor.
		@endinternal
		@liveexample{The following code shows how arbitrary library exceptions can be
		caught.,exception}
		@since version 3.0.0
		*/
		class exception : public std::exception
		{
		public:
			/// returns the explanatory string
			JSON_HEDLEY_RETURNS_NON_NULL
				const char* what() const noexcept override
			{
				return m.what();
			}

			/// the id of the exception
			const int id;

		protected:
			JSON_HEDLEY_NON_NULL(3)
				exception(int id_, const char* what_arg) : id(id_), m(what_arg) {}

			static std::string name(const std::string& ename, int id_)
			{
				return "[json.exception." + ename + "." + std::to_string(id_) + "] ";
			}

		private:
			/// an exception object as storage for error messages
			std::runtime_error m;
		};

		/*!
		@brief exception indicating a parse error
		This exception is thrown by the library when a parse error occurs. Parse errors
		can occur during the deserialization of JSON text, CBOR, MessagePack, as well
		as when using JSON Patch.
		Member @a byte holds the byte index of the last read character in the input
		file.
		Exceptions have ids 1xx.
		name / id                      | example message | description
		------------------------------ | --------------- | -------------------------
		json.exception.parse_error.101 | parse error at 2: unexpected end of input; expected string literal | This error indicates a syntax error while deserializing a JSON text. The error message describes that an unexpected token (character) was encountered, and the member @a byte indicates the error position.
		json.exception.parse_error.102 | parse error at 14: missing or wrong low surrogate | JSON uses the `\uxxxx` format to describe Unicode characters. Code points above above 0xFFFF are split into two `\uxxxx` entries ("surrogate pairs"). This error indicates that the surrogate pair is incomplete or contains an invalid code point.
		json.exception.parse_error.103 | parse error: code points above 0x10FFFF are invalid | Unicode supports code points up to 0x10FFFF. Code points above 0x10FFFF are invalid.
		json.exception.parse_error.104 | parse error: JSON patch must be an array of objects | [RFC 6902](https://tools.ietf.org/html/rfc6902) requires a JSON Patch document to be a JSON document that represents an array of objects.
		json.exception.parse_error.105 | parse error: operation must have string member 'op' | An operation of a JSON Patch document must contain exactly one "op" member, whose value indicates the operation to perform. Its value must be one of "add", "remove", "replace", "move", "copy", or "test"; other values are errors.
		json.exception.parse_error.106 | parse error: array index '01' must not begin with '0' | An array index in a JSON Pointer ([RFC 6901](https://tools.ietf.org/html/rfc6901)) may be `0` or any number without a leading `0`.
		json.exception.parse_error.107 | parse error: JSON pointer must be empty or begin with '/' - was: 'foo' | A JSON Pointer must be a Unicode string containing a sequence of zero or more reference tokens, each prefixed by a `/` character.
		json.exception.parse_error.108 | parse error: escape character '~' must be followed with '0' or '1' | In a JSON Pointer, only `~0` and `~1` are valid escape sequences.
		json.exception.parse_error.109 | parse error: array index 'one' is not a number | A JSON Pointer array index must be a number.
		json.exception.parse_error.110 | parse error at 1: cannot read 2 bytes from vector | When parsing CBOR or MessagePack, the byte vector ends before the complete value has been read.
		json.exception.parse_error.112 | parse error at 1: error reading CBOR; last byte: 0xF8 | Not all types of CBOR or MessagePack are supported. This exception occurs if an unsupported byte was read.
		json.exception.parse_error.113 | parse error at 2: expected a CBOR string; last byte: 0x98 | While parsing a map key, a value that is not a string has been read.
		json.exception.parse_error.114 | parse error: Unsupported BSON record type 0x0F | The parsing of the corresponding BSON record type is not implemented (yet).
		@note For an input with n bytes, 1 is the index of the first character and n+1
			  is the index of the terminating null byte or the end of file. This also
			  holds true when reading a byte vector (CBOR or MessagePack).
		@liveexample{The following code shows how a `parse_error` exception can be
		caught.,parse_error}
		@sa - @ref exception for the base class of the library exceptions
		@sa - @ref invalid_iterator for exceptions indicating errors with iterators
		@sa - @ref type_error for exceptions indicating executing a member function with
							a wrong type
		@sa - @ref out_of_range for exceptions indicating access out of the defined range
		@sa - @ref other_error for exceptions indicating other library errors
		@since version 3.0.0
		*/
		class parse_error : public exception
		{
		public:
			/*!
			@brief create a parse error exception
			@param[in] id_       the id of the exception
			@param[in] pos       the position where the error occurred (or with
								 chars_read_total=0 if the position cannot be
								 determined)
			@param[in] what_arg  the explanatory string
			@return parse_error object
			*/
			static parse_error create(int id_, const position_t& pos, const std::string& what_arg)
			{
				std::string w = exception::name("parse_error", id_) + "parse error" +
					position_string(pos) + ": " + what_arg;
				return parse_error(id_, pos.chars_read_total, w.c_str());
			}

			static parse_error create(int id_, std::size_t byte_, const std::string& what_arg)
			{
				std::string w = exception::name("parse_error", id_) + "parse error" +
					(byte_ != 0 ? (" at byte " + std::to_string(byte_)) : "") +
					": " + what_arg;
				return parse_error(id_, byte_, w.c_str());
			}

			/*!
			@brief byte index of the parse error
			The byte index of the last read character in the input file.
			@note For an input with n bytes, 1 is the index of the first character and
				  n+1 is the index of the terminating null byte or the end of file.
				  This also holds true when reading a byte vector (CBOR or MessagePack).
			*/
			const std::size_t byte;

		private:
			parse_error(int id_, std::size_t byte_, const char* what_arg)
				: exception(id_, what_arg), byte(byte_) {}

			static std::string position_string(const position_t& pos)
			{
				return " at line " + std::to_string(pos.lines_read + 1) +
					", column " + std::to_string(pos.chars_read_current_line);
			}
		};

		/*!
		@brief exception indicating errors with iterators
		This exception is thrown if iterators passed to a library function do not match
		the expected semantics.
		Exceptions have ids 2xx.
		name / id                           | example message | description
		----------------------------------- | --------------- | -------------------------
		json.exception.invalid_iterator.201 | iterators are not compatible | The iterators passed to constructor @ref basic_json(InputIT first, InputIT last) are not compatible, meaning they do not belong to the same container. Therefore, the range (@a first, @a last) is invalid.
		json.exception.invalid_iterator.202 | iterator does not fit current value | In an erase or insert function, the passed iterator @a pos does not belong to the JSON value for which the function was called. It hence does not define a valid position for the deletion/insertion.
		json.exception.invalid_iterator.203 | iterators do not fit current value | Either iterator passed to function @ref erase(IteratorType first, IteratorType last) does not belong to the JSON value from which values shall be erased. It hence does not define a valid range to delete values from.
		json.exception.invalid_iterator.204 | iterators out of range | When an iterator range for a primitive type (number, boolean, or string) is passed to a constructor or an erase function, this range has to be exactly (@ref begin(), @ref end()), because this is the only way the single stored value is expressed. All other ranges are invalid.
		json.exception.invalid_iterator.205 | iterator out of range | When an iterator for a primitive type (number, boolean, or string) is passed to an erase function, the iterator has to be the @ref begin() iterator, because it is the only way to address the stored value. All other iterators are invalid.
		json.exception.invalid_iterator.206 | cannot construct with iterators from null | The iterators passed to constructor @ref basic_json(InputIT first, InputIT last) belong to a JSON null value and hence to not define a valid range.
		json.exception.invalid_iterator.207 | cannot use key() for non-object iterators | The key() member function can only be used on iterators belonging to a JSON object, because other types do not have a concept of a key.
		json.exception.invalid_iterator.208 | cannot use operator[] for object iterators | The operator[] to specify a concrete offset cannot be used on iterators belonging to a JSON object, because JSON objects are unordered.
		json.exception.invalid_iterator.209 | cannot use offsets with object iterators | The offset operators (+, -, +=, -=) cannot be used on iterators belonging to a JSON object, because JSON objects are unordered.
		json.exception.invalid_iterator.210 | iterators do not fit | The iterator range passed to the insert function are not compatible, meaning they do not belong to the same container. Therefore, the range (@a first, @a last) is invalid.
		json.exception.invalid_iterator.211 | passed iterators may not belong to container | The iterator range passed to the insert function must not be a subrange of the container to insert to.
		json.exception.invalid_iterator.212 | cannot compare iterators of different containers | When two iterators are compared, they must belong to the same container.
		json.exception.invalid_iterator.213 | cannot compare order of object iterators | The order of object iterators cannot be compared, because JSON objects are unordered.
		json.exception.invalid_iterator.214 | cannot get value | Cannot get value for iterator: Either the iterator belongs to a null value or it is an iterator to a primitive type (number, boolean, or string), but the iterator is different to @ref begin().
		@liveexample{The following code shows how an `invalid_iterator` exception can be
		caught.,invalid_iterator}
		@sa - @ref exception for the base class of the library exceptions
		@sa - @ref parse_error for exceptions indicating a parse error
		@sa - @ref type_error for exceptions indicating executing a member function with
							a wrong type
		@sa - @ref out_of_range for exceptions indicating access out of the defined range
		@sa - @ref other_error for exceptions indicating other library errors
		@since version 3.0.0
		*/
		class invalid_iterator : public exception
		{
		public:
			static invalid_iterator create(int id_, const std::string& what_arg)
			{
				std::string w = exception::name("invalid_iterator", id_) + what_arg;
				return invalid_iterator(id_, w.c_str());
			}

		private:
			JSON_HEDLEY_NON_NULL(3)
				invalid_iterator(int id_, const char* what_arg)
				: exception(id_, what_arg) {}
		};

		/*!
		@brief exception indicating executing a member function with a wrong type
		This exception is thrown in case of a type error; that is, a library function is
		executed on a JSON value whose type does not match the expected semantics.
		Exceptions have ids 3xx.
		name / id                     | example message | description
		----------------------------- | --------------- | -------------------------
		json.exception.type_error.301 | cannot create object from initializer list | To create an object from an initializer list, the initializer list must consist only of a list of pairs whose first element is a string. When this constraint is violated, an array is created instead.
		json.exception.type_error.302 | type must be object, but is array | During implicit or explicit value conversion, the JSON type must be compatible to the target type. For instance, a JSON string can only be converted into string types, but not into numbers or boolean types.
		json.exception.type_error.303 | incompatible ReferenceType for get_ref, actual type is object | To retrieve a reference to a value stored in a @ref basic_json object with @ref get_ref, the type of the reference must match the value type. For instance, for a JSON array, the @a ReferenceType must be @ref array_t &.
		json.exception.type_error.304 | cannot use at() with string | The @ref at() member functions can only be executed for certain JSON types.
		json.exception.type_error.305 | cannot use operator[] with string | The @ref operator[] member functions can only be executed for certain JSON types.
		json.exception.type_error.306 | cannot use value() with string | The @ref value() member functions can only be executed for certain JSON types.
		json.exception.type_error.307 | cannot use erase() with string | The @ref erase() member functions can only be executed for certain JSON types.
		json.exception.type_error.308 | cannot use push_back() with string | The @ref push_back() and @ref operator+= member functions can only be executed for certain JSON types.
		json.exception.type_error.309 | cannot use insert() with | The @ref insert() member functions can only be executed for certain JSON types.
		json.exception.type_error.310 | cannot use swap() with number | The @ref swap() member functions can only be executed for certain JSON types.
		json.exception.type_error.311 | cannot use emplace_back() with string | The @ref emplace_back() member function can only be executed for certain JSON types.
		json.exception.type_error.312 | cannot use update() with string | The @ref update() member functions can only be executed for certain JSON types.
		json.exception.type_error.313 | invalid value to unflatten | The @ref unflatten function converts an object whose keys are JSON Pointers back into an arbitrary nested JSON value. The JSON Pointers must not overlap, because then the resulting value would not be well defined.
		json.exception.type_error.314 | only objects can be unflattened | The @ref unflatten function only works for an object whose keys are JSON Pointers.
		json.exception.type_error.315 | values in object must be primitive | The @ref unflatten function only works for an object whose keys are JSON Pointers and whose values are primitive.
		json.exception.type_error.316 | invalid UTF-8 byte at index 10: 0x7E | The @ref dump function only works with UTF-8 encoded strings; that is, if you assign a `std::string` to a JSON value, make sure it is UTF-8 encoded. |
		json.exception.type_error.317 | JSON value cannot be serialized to requested format | The dynamic type of the object cannot be represented in the requested serialization format (e.g. a raw `true` or `null` JSON object cannot be serialized to BSON) |
		@liveexample{The following code shows how a `type_error` exception can be
		caught.,type_error}
		@sa - @ref exception for the base class of the library exceptions
		@sa - @ref parse_error for exceptions indicating a parse error
		@sa - @ref invalid_iterator for exceptions indicating errors with iterators
		@sa - @ref out_of_range for exceptions indicating access out of the defined range
		@sa - @ref other_error for exceptions indicating other library errors
		@since version 3.0.0
		*/
		class type_error : public exception
		{
		public:
			static type_error create(int id_, const std::string& what_arg)
			{
				std::string w = exception::name("type_error", id_) + what_arg;
				return type_error(id_, w.c_str());
			}

		private:
			JSON_HEDLEY_NON_NULL(3)
				type_error(int id_, const char* what_arg) : exception(id_, what_arg) {}
		};

		/*!
		@brief exception indicating access out of the defined range
		This exception is thrown in case a library function is called on an input
		parameter that exceeds the expected range, for instance in case of array
		indices or nonexisting object keys.
		Exceptions have ids 4xx.
		name / id                       | example message | description
		------------------------------- | --------------- | -------------------------
		json.exception.out_of_range.401 | array index 3 is out of range | The provided array index @a i is larger than @a size-1.
		json.exception.out_of_range.402 | array index '-' (3) is out of range | The special array index `-` in a JSON Pointer never describes a valid element of the array, but the index past the end. That is, it can only be used to add elements at this position, but not to read it.
		json.exception.out_of_range.403 | key 'foo' not found | The provided key was not found in the JSON object.
		json.exception.out_of_range.404 | unresolved reference token 'foo' | A reference token in a JSON Pointer could not be resolved.
		json.exception.out_of_range.405 | JSON pointer has no parent | The JSON Patch operations 'remove' and 'add' can not be applied to the root element of the JSON value.
		json.exception.out_of_range.406 | number overflow parsing '10E1000' | A parsed number could not be stored as without changing it to NaN or INF.
		json.exception.out_of_range.407 | number overflow serializing '9223372036854775808' | UBJSON and BSON only support integer numbers up to 9223372036854775807. |
		json.exception.out_of_range.408 | excessive array size: 8658170730974374167 | The size (following `#`) of an UBJSON array or object exceeds the maximal capacity. |
		json.exception.out_of_range.409 | BSON key cannot contain code point U+0000 (at byte 2) | Key identifiers to be serialized to BSON cannot contain code point U+0000, since the key is stored as zero-terminated c-string |
		@liveexample{The following code shows how an `out_of_range` exception can be
		caught.,out_of_range}
		@sa - @ref exception for the base class of the library exceptions
		@sa - @ref parse_error for exceptions indicating a parse error
		@sa - @ref invalid_iterator for exceptions indicating errors with iterators
		@sa - @ref type_error for exceptions indicating executing a member function with
							a wrong type
		@sa - @ref other_error for exceptions indicating other library errors
		@since version 3.0.0
		*/
		class out_of_range : public exception
		{
		public:
			static out_of_range create(int id_, const std::string& what_arg)
			{
				std::string w = exception::name("out_of_range", id_) + what_arg;
				return out_of_range(id_, w.c_str());
			}

		private:
			JSON_HEDLEY_NON_NULL(3)
				out_of_range(int id_, const char* what_arg) : exception(id_, what_arg) {}
		};

		/*!
		@brief exception indicating other library errors
		This exception is thrown in case of errors that cannot be classified with the
		other exception types.
		Exceptions have ids 5xx.
		name / id                      | example message | description
		------------------------------ | --------------- | -------------------------
		json.exception.other_error.501 | unsuccessful: {"op":"test","path":"/baz", "value":"bar"} | A JSON Patch operation 'test' failed. The unsuccessful operation is also printed.
		@sa - @ref exception for the base class of the library exceptions
		@sa - @ref parse_error for exceptions indicating a parse error
		@sa - @ref invalid_iterator for exceptions indicating errors with iterators
		@sa - @ref type_error for exceptions indicating executing a member function with
							a wrong type
		@sa - @ref out_of_range for exceptions indicating access out of the defined range
		@liveexample{The following code shows how an `other_error` exception can be
		caught.,other_error}
		@since version 3.0.0
		*/
		class other_error : public exception
		{
		public:
			static other_error create(int id_, const std::string& what_arg)
			{
				std::string w = exception::name("other_error", id_) + what_arg;
				return other_error(id_, w.c_str());
			}

		private:
			JSON_HEDLEY_NON_NULL(3)
				other_error(int id_, const char* what_arg) : exception(id_, what_arg) {}
		};
	}  // namespace detail
}  // namespace nlohmann

// #include <nlohmann/detail/macro_scope.hpp>

// #include <nlohmann/detail/meta/cpp_future.hpp>


#include <ciso646> // not
#include <cstddef> // size_t
#include <type_traits> // conditional, enable_if, false_type, integral_constant, is_constructible, is_integral, is_same, remove_cv, remove_reference, true_type

namespace nlohmann
{
	namespace detail
	{
		// alias templates to reduce boilerplate
		template<bool B, typename T = void>
		using enable_if_t = typename std::enable_if<B, T>::type;

		template<typename T>
		using uncvref_t = typename std::remove_cv<typename std::remove_reference<T>::type>::type;

		// implementation of C++14 index_sequence and affiliates
		// source: https://stackoverflow.com/a/32223343
		template<std::size_t... Ints>
		struct index_sequence
		{
			using type = index_sequence;
			using value_type = std::size_t;
			static constexpr std::size_t size() noexcept
			{
				return sizeof...(Ints);
			}
		};

		template<class Sequence1, class Sequence2>
		struct merge_and_renumber;

		template<std::size_t... I1, std::size_t... I2>
		struct merge_and_renumber<index_sequence<I1...>, index_sequence<I2...>>
			: index_sequence < I1..., (sizeof...(I1) + I2)... > {};

		template<std::size_t N>
		struct make_index_sequence
			: merge_and_renumber < typename make_index_sequence < N / 2 >::type,
			typename make_index_sequence < N - N / 2 >::type > {};

		template<> struct make_index_sequence<0> : index_sequence<> {};
		template<> struct make_index_sequence<1> : index_sequence<0> {};

		template<typename... Ts>
		using index_sequence_for = make_index_sequence<sizeof...(Ts)>;

		// dispatch utility (taken from ranges-v3)
		template<unsigned N> struct priority_tag : priority_tag < N - 1 > {};
		template<> struct priority_tag<0> {};

		// taken from ranges-v3
		template<typename T>
		struct static_const
		{
			static constexpr T value{};
		};

		template<typename T>
		constexpr T static_const<T>::value;
	}  // namespace detail
}  // namespace nlohmann

// #include <nlohmann/detail/meta/type_traits.hpp>


#include <ciso646> // not
#include <limits> // numeric_limits
#include <type_traits> // false_type, is_constructible, is_integral, is_same, true_type
#include <utility> // declval

// #include <nlohmann/detail/iterators/iterator_traits.hpp>


#include <iterator> // random_access_iterator_tag

// #include <nlohmann/detail/meta/void_t.hpp>


namespace nlohmann
{
	namespace detail
	{
		template <typename ...Ts> struct make_void
		{
			using type = void;
		};
		template <typename ...Ts> using void_t = typename make_void<Ts...>::type;
	} // namespace detail
}  // namespace nlohmann

// #include <nlohmann/detail/meta/cpp_future.hpp>


namespace nlohmann
{
	namespace detail
	{
		template <typename It, typename = void>
		struct iterator_types {};

		template <typename It>
		struct iterator_types <
			It,
			void_t<typename It::difference_type, typename It::value_type, typename It::pointer,
			typename It::reference, typename It::iterator_category >>
		{
			using difference_type = typename It::difference_type;
			using value_type = typename It::value_type;
			using pointer = typename It::pointer;
			using reference = typename It::reference;
			using iterator_category = typename It::iterator_category;
		};

		// This is required as some compilers implement std::iterator_traits in a way that
		// doesn't work with SFINAE. See https://github.com/nlohmann/json/issues/1341.
		template <typename T, typename = void>
		struct iterator_traits
		{
		};

		template <typename T>
		struct iterator_traits < T, enable_if_t < !std::is_pointer<T>::value >>
			: iterator_types<T>
		{
		};

		template <typename T>
		struct iterator_traits<T*, enable_if_t<std::is_object<T>::value>>
		{
			using iterator_category = std::random_access_iterator_tag;
			using value_type = T;
			using difference_type = ptrdiff_t;
			using pointer = T*;
			using reference = T&;
		};
	} // namespace detail
} // namespace nlohmann

// #include <nlohmann/detail/macro_scope.hpp>

// #include <nlohmann/detail/meta/cpp_future.hpp>

// #include <nlohmann/detail/meta/detected.hpp>


#include <type_traits>

// #include <nlohmann/detail/meta/void_t.hpp>


// http://en.cppreference.com/w/cpp/experimental/is_detected
namespace nlohmann
{
	namespace detail
	{
		struct nonesuch
		{
			nonesuch() = delete;
			~nonesuch() = delete;
			nonesuch(nonesuch const&) = delete;
			nonesuch(nonesuch const&&) = delete;
			void operator=(nonesuch const&) = delete;
			void operator=(nonesuch&&) = delete;
		};

		template <class Default,
			class AlwaysVoid,
			template <class...> class Op,
			class... Args>
			struct detector
		{
			using value_t = std::false_type;
			using type = Default;
		};

		template <class Default, template <class...> class Op, class... Args>
		struct detector<Default, void_t<Op<Args...>>, Op, Args...>
		{
			using value_t = std::true_type;
			using type = Op<Args...>;
		};

		template <template <class...> class Op, class... Args>
		using is_detected = typename detector<nonesuch, void, Op, Args...>::value_t;

		template <template <class...> class Op, class... Args>
		using detected_t = typename detector<nonesuch, void, Op, Args...>::type;

		template <class Default, template <class...> class Op, class... Args>
		using detected_or = detector<Default, void, Op, Args...>;

		template <class Default, template <class...> class Op, class... Args>
		using detected_or_t = typename detected_or<Default, Op, Args...>::type;

		template <class Expected, template <class...> class Op, class... Args>
		using is_detected_exact = std::is_same<Expected, detected_t<Op, Args...>>;

		template <class To, template <class...> class Op, class... Args>
		using is_detected_convertible =
			std::is_convertible<detected_t<Op, Args...>, To>;
	}  // namespace detail
}  // namespace nlohmann

// #include <nlohmann/json_fwd.hpp>
#ifndef INCLUDE_NLOHMANN_JSON_FWD_HPP_
#define INCLUDE_NLOHMANN_JSON_FWD_HPP_

#include <cstdint> // int64_t, uint64_t
#include <map> // map
#include <memory> // allocator
#include <string> // string
#include <vector> // vector

/*!
@brief namespace for Niels Lohmann
@see https://github.com/nlohmann
@since version 1.0.0
*/
namespace nlohmann
{
	/*!
	@brief default JSONSerializer template argument
	This serializer ignores the template arguments and uses ADL
	([argument-dependent lookup](https://en.cppreference.com/w/cpp/language/adl))
	for serialization.
	*/
	template<typename T = void, typename SFINAE = void>
	struct adl_serializer;

	template<template<typename U, typename V, typename... Args> class ObjectType =
		std::map,
		template<typename U, typename... Args> class ArrayType = std::vector,
		class StringType = std::string, class BooleanType = bool,
		class NumberIntegerType = std::int64_t,
		class NumberUnsignedType = std::uint64_t,
		class NumberFloatType = double,
		template<typename U> class AllocatorType = std::allocator,
		template<typename T, typename SFINAE = void> class JSONSerializer =
		adl_serializer>
		class basic_json;

	/*!
	@brief JSON Pointer
	A JSON pointer defines a string syntax for identifying a specific value
	within a JSON document. It can be used with functions `at` and
	`operator[]`. Furthermore, JSON pointers are the base for JSON patches.
	@sa [RFC 6901](https://tools.ietf.org/html/rfc6901)
	@since version 2.0.0
	*/
	template<typename BasicJsonType>
	class json_pointer;

	/*!
	@brief default JSON class
	This type is the default specialization of the @ref basic_json class which
	uses the standard template types.
	@since version 1.0.0
	*/
	using json = basic_json<>;
}  // namespace nlohmann

#endif  // INCLUDE_NLOHMANN_JSON_FWD_HPP_


namespace nlohmann
{
	/*!
	@brief detail namespace with internal helper functions
	This namespace collects functions that should not be exposed,
	implementations of some @ref basic_json methods, and meta-programming helpers.
	@since version 2.1.0
	*/
	namespace detail
	{
		/////////////
		// helpers //
		/////////////

		// Note to maintainers:
		//
		// Every trait in this file expects a non CV-qualified type.
		// The only exceptions are in the 'aliases for detected' section
		// (i.e. those of the form: decltype(T::member_function(std::declval<T>())))
		//
		// In this case, T has to be properly CV-qualified to constraint the function arguments
		// (e.g. to_json(BasicJsonType&, const T&))

		template<typename> struct is_basic_json : std::false_type {};

		NLOHMANN_BASIC_JSON_TPL_DECLARATION
			struct is_basic_json<NLOHMANN_BASIC_JSON_TPL> : std::true_type {};

		//////////////////////////
		// aliases for detected //
		//////////////////////////

		template <typename T>
		using mapped_type_t = typename T::mapped_type;

		template <typename T>
		using key_type_t = typename T::key_type;

		template <typename T>
		using value_type_t = typename T::value_type;

		template <typename T>
		using difference_type_t = typename T::difference_type;

		template <typename T>
		using pointer_t = typename T::pointer;

		template <typename T>
		using reference_t = typename T::reference;

		template <typename T>
		using iterator_category_t = typename T::iterator_category;

		template <typename T>
		using iterator_t = typename T::iterator;

		template <typename T, typename... Args>
		using to_json_function = decltype(T::to_json(std::declval<Args>()...));

		template <typename T, typename... Args>
		using from_json_function = decltype(T::from_json(std::declval<Args>()...));

		template <typename T, typename U>
		using get_template_function = decltype(std::declval<T>().template get<U>());

		// trait checking if JSONSerializer<T>::from_json(json const&, udt&) exists
		template <typename BasicJsonType, typename T, typename = void>
		struct has_from_json : std::false_type {};

		template <typename BasicJsonType, typename T>
		struct has_from_json<BasicJsonType, T,
			enable_if_t<not is_basic_json<T>::value>>
		{
			using serializer = typename BasicJsonType::template json_serializer<T, void>;

			static constexpr bool value =
				is_detected_exact<void, from_json_function, serializer,
				const BasicJsonType&, T&>::value;
		};

		// This trait checks if JSONSerializer<T>::from_json(json const&) exists
		// this overload is used for non-default-constructible user-defined-types
		template <typename BasicJsonType, typename T, typename = void>
		struct has_non_default_from_json : std::false_type {};

		template<typename BasicJsonType, typename T>
		struct has_non_default_from_json<BasicJsonType, T, enable_if_t<not is_basic_json<T>::value>>
		{
			using serializer = typename BasicJsonType::template json_serializer<T, void>;

			static constexpr bool value =
				is_detected_exact<T, from_json_function, serializer,
				const BasicJsonType&>::value;
		};

		// This trait checks if BasicJsonType::json_serializer<T>::to_json exists
		// Do not evaluate the trait when T is a basic_json type, to avoid template instantiation infinite recursion.
		template <typename BasicJsonType, typename T, typename = void>
		struct has_to_json : std::false_type {};

		template <typename BasicJsonType, typename T>
		struct has_to_json<BasicJsonType, T, enable_if_t<not is_basic_json<T>::value>>
		{
			using serializer = typename BasicJsonType::template json_serializer<T, void>;

			static constexpr bool value =
				is_detected_exact<void, to_json_function, serializer, BasicJsonType&,
				T>::value;
		};


		///////////////////
		// is_ functions //
		///////////////////

		template <typename T, typename = void>
		struct is_iterator_traits : std::false_type {};

		template <typename T>
		struct is_iterator_traits<iterator_traits<T>>
		{
		private:
			using traits = iterator_traits<T>;

		public:
			static constexpr auto value =
				is_detected<value_type_t, traits>::value &&
				is_detected<difference_type_t, traits>::value &&
				is_detected<pointer_t, traits>::value &&
				is_detected<iterator_category_t, traits>::value &&
				is_detected<reference_t, traits>::value;
		};

		// source: https://stackoverflow.com/a/37193089/4116453

		template <typename T, typename = void>
		struct is_complete_type : std::false_type {};

		template <typename T>
		struct is_complete_type<T, decltype(void(sizeof(T)))> : std::true_type {};

		template <typename BasicJsonType, typename CompatibleObjectType,
			typename = void>
			struct is_compatible_object_type_impl : std::false_type {};

		template <typename BasicJsonType, typename CompatibleObjectType>
		struct is_compatible_object_type_impl <
			BasicJsonType, CompatibleObjectType,
			enable_if_t<is_detected<mapped_type_t, CompatibleObjectType>::value and
			is_detected<key_type_t, CompatibleObjectType>::value >>
		{

			using object_t = typename BasicJsonType::object_t;

			// macOS's is_constructible does not play well with nonesuch...
			static constexpr bool value =
				std::is_constructible<typename object_t::key_type,
				typename CompatibleObjectType::key_type>::value and
				std::is_constructible<typename object_t::mapped_type,
				typename CompatibleObjectType::mapped_type>::value;
		};

		template <typename BasicJsonType, typename CompatibleObjectType>
		struct is_compatible_object_type
			: is_compatible_object_type_impl<BasicJsonType, CompatibleObjectType> {};

		template <typename BasicJsonType, typename ConstructibleObjectType,
			typename = void>
			struct is_constructible_object_type_impl : std::false_type {};

		template <typename BasicJsonType, typename ConstructibleObjectType>
		struct is_constructible_object_type_impl <
			BasicJsonType, ConstructibleObjectType,
			enable_if_t<is_detected<mapped_type_t, ConstructibleObjectType>::value and
			is_detected<key_type_t, ConstructibleObjectType>::value >>
		{
			using object_t = typename BasicJsonType::object_t;

			static constexpr bool value =
				(std::is_default_constructible<ConstructibleObjectType>::value and
				(std::is_move_assignable<ConstructibleObjectType>::value or
					std::is_copy_assignable<ConstructibleObjectType>::value) and
					(std::is_constructible<typename ConstructibleObjectType::key_type,
						typename object_t::key_type>::value and
						std::is_same <
						typename object_t::mapped_type,
						typename ConstructibleObjectType::mapped_type >::value)) or
						(has_from_json<BasicJsonType,
							typename ConstructibleObjectType::mapped_type>::value or
							has_non_default_from_json <
							BasicJsonType,
							typename ConstructibleObjectType::mapped_type >::value);
		};

		template <typename BasicJsonType, typename ConstructibleObjectType>
		struct is_constructible_object_type
			: is_constructible_object_type_impl<BasicJsonType,
			ConstructibleObjectType> {};

		template <typename BasicJsonType, typename CompatibleStringType,
			typename = void>
			struct is_compatible_string_type_impl : std::false_type {};

		template <typename BasicJsonType, typename CompatibleStringType>
		struct is_compatible_string_type_impl <
			BasicJsonType, CompatibleStringType,
			enable_if_t<is_detected_exact<typename BasicJsonType::string_t::value_type,
			value_type_t, CompatibleStringType>::value >>
		{
			static constexpr auto value =
				std::is_constructible<typename BasicJsonType::string_t, CompatibleStringType>::value;
		};

		template <typename BasicJsonType, typename ConstructibleStringType>
		struct is_compatible_string_type
			: is_compatible_string_type_impl<BasicJsonType, ConstructibleStringType> {};

		template <typename BasicJsonType, typename ConstructibleStringType,
			typename = void>
			struct is_constructible_string_type_impl : std::false_type {};

		template <typename BasicJsonType, typename ConstructibleStringType>
		struct is_constructible_string_type_impl <
			BasicJsonType, ConstructibleStringType,
			enable_if_t<is_detected_exact<typename BasicJsonType::string_t::value_type,
			value_type_t, ConstructibleStringType>::value >>
		{
			static constexpr auto value =
				std::is_constructible<ConstructibleStringType,
				typename BasicJsonType::string_t>::value;
		};

		template <typename BasicJsonType, typename ConstructibleStringType>
		struct is_constructible_string_type
			: is_constructible_string_type_impl<BasicJsonType, ConstructibleStringType> {};

		template <typename BasicJsonType, typename CompatibleArrayType, typename = void>
		struct is_compatible_array_type_impl : std::false_type {};

		template <typename BasicJsonType, typename CompatibleArrayType>
		struct is_compatible_array_type_impl <
			BasicJsonType, CompatibleArrayType,
			enable_if_t<is_detected<value_type_t, CompatibleArrayType>::value and
			is_detected<iterator_t, CompatibleArrayType>::value and
			// This is needed because json_reverse_iterator has a ::iterator type...
			// Therefore it is detected as a CompatibleArrayType.
			// The real fix would be to have an Iterable concept.
			not is_iterator_traits<
			iterator_traits<CompatibleArrayType>>::value >>
		{
			static constexpr bool value =
				std::is_constructible<BasicJsonType,
				typename CompatibleArrayType::value_type>::value;
		};

		template <typename BasicJsonType, typename CompatibleArrayType>
		struct is_compatible_array_type
			: is_compatible_array_type_impl<BasicJsonType, CompatibleArrayType> {};

		template <typename BasicJsonType, typename ConstructibleArrayType, typename = void>
		struct is_constructible_array_type_impl : std::false_type {};

		template <typename BasicJsonType, typename ConstructibleArrayType>
		struct is_constructible_array_type_impl <
			BasicJsonType, ConstructibleArrayType,
			enable_if_t<std::is_same<ConstructibleArrayType,
			typename BasicJsonType::value_type>::value >>
			: std::true_type {};

		template <typename BasicJsonType, typename ConstructibleArrayType>
		struct is_constructible_array_type_impl <
			BasicJsonType, ConstructibleArrayType,
			enable_if_t<not std::is_same<ConstructibleArrayType,
			typename BasicJsonType::value_type>::value and
			std::is_default_constructible<ConstructibleArrayType>::value and
			(std::is_move_assignable<ConstructibleArrayType>::value or
				std::is_copy_assignable<ConstructibleArrayType>::value) and
			is_detected<value_type_t, ConstructibleArrayType>::value and
			is_detected<iterator_t, ConstructibleArrayType>::value and
			is_complete_type<
			detected_t<value_type_t, ConstructibleArrayType>>::value >>
		{
			static constexpr bool value =
				// This is needed because json_reverse_iterator has a ::iterator type,
				// furthermore, std::back_insert_iterator (and other iterators) have a
				// base class `iterator`... Therefore it is detected as a
				// ConstructibleArrayType. The real fix would be to have an Iterable
				// concept.
				not is_iterator_traits<iterator_traits<ConstructibleArrayType>>::value and

				(std::is_same<typename ConstructibleArrayType::value_type,
					typename BasicJsonType::array_t::value_type>::value or
					has_from_json<BasicJsonType,
					typename ConstructibleArrayType::value_type>::value or
					has_non_default_from_json <
					BasicJsonType, typename ConstructibleArrayType::value_type >::value);
		};

		template <typename BasicJsonType, typename ConstructibleArrayType>
		struct is_constructible_array_type
			: is_constructible_array_type_impl<BasicJsonType, ConstructibleArrayType> {};

		template <typename RealIntegerType, typename CompatibleNumberIntegerType,
			typename = void>
			struct is_compatible_integer_type_impl : std::false_type {};

		template <typename RealIntegerType, typename CompatibleNumberIntegerType>
		struct is_compatible_integer_type_impl <
			RealIntegerType, CompatibleNumberIntegerType,
			enable_if_t<std::is_integral<RealIntegerType>::value and
			std::is_integral<CompatibleNumberIntegerType>::value and
			not std::is_same<bool, CompatibleNumberIntegerType>::value >>
		{
			// is there an assert somewhere on overflows?
			using RealLimits = std::numeric_limits<RealIntegerType>;
			using CompatibleLimits = std::numeric_limits<CompatibleNumberIntegerType>;

			static constexpr auto value =
				std::is_constructible<RealIntegerType,
				CompatibleNumberIntegerType>::value and
				CompatibleLimits::is_integer and
				RealLimits::is_signed == CompatibleLimits::is_signed;
		};

		template <typename RealIntegerType, typename CompatibleNumberIntegerType>
		struct is_compatible_integer_type
			: is_compatible_integer_type_impl<RealIntegerType,
			CompatibleNumberIntegerType> {};

		template <typename BasicJsonType, typename CompatibleType, typename = void>
		struct is_compatible_type_impl : std::false_type {};

		template <typename BasicJsonType, typename CompatibleType>
		struct is_compatible_type_impl <
			BasicJsonType, CompatibleType,
			enable_if_t<is_complete_type<CompatibleType>::value >>
		{
			static constexpr bool value =
				has_to_json<BasicJsonType, CompatibleType>::value;
		};

		template <typename BasicJsonType, typename CompatibleType>
		struct is_compatible_type
			: is_compatible_type_impl<BasicJsonType, CompatibleType> {};
	}  // namespace detail
}  // namespace nlohmann

// #include <nlohmann/detail/value_t.hpp>


#include <array> // array
#include <ciso646> // and
#include <cstddef> // size_t
#include <cstdint> // uint8_t
#include <string> // string

namespace nlohmann
{
	namespace detail
	{
		///////////////////////////
		// JSON type enumeration //
		///////////////////////////

		/*!
		@brief the JSON type enumeration
		This enumeration collects the different JSON types. It is internally used to
		distinguish the stored values, and the functions @ref basic_json::is_null(),
		@ref basic_json::is_object(), @ref basic_json::is_array(),
		@ref basic_json::is_string(), @ref basic_json::is_boolean(),
		@ref basic_json::is_number() (with @ref basic_json::is_number_integer(),
		@ref basic_json::is_number_unsigned(), and @ref basic_json::is_number_float()),
		@ref basic_json::is_discarded(), @ref basic_json::is_primitive(), and
		@ref basic_json::is_structured() rely on it.
		@note There are three enumeration entries (number_integer, number_unsigned, and
		number_float), because the library distinguishes these three types for numbers:
		@ref basic_json::number_unsigned_t is used for unsigned integers,
		@ref basic_json::number_integer_t is used for signed integers, and
		@ref basic_json::number_float_t is used for floating-point numbers or to
		approximate integers which do not fit in the limits of their respective type.
		@sa @ref basic_json::basic_json(const value_t value_type) -- create a JSON
		value with the default value for a given type
		@since version 1.0.0
		*/
		enum class value_t : std::uint8_t
		{
			null,             ///< null value
			object,           ///< object (unordered set of name/value pairs)
			array,            ///< array (ordered collection of values)
			string,           ///< string value
			boolean,          ///< boolean value
			number_integer,   ///< number value (signed integer)
			number_unsigned,  ///< number value (unsigned integer)
			number_float,     ///< number value (floating-point)
			discarded         ///< discarded by the the parser callback function
		};

		/*!
		@brief comparison operator for JSON types
		Returns an ordering that is similar to Python:
		- order: null < boolean < number < object < array < string
		- furthermore, each type is not smaller than itself
		- discarded values are not comparable
		@since version 1.0.0
		*/
		inline bool operator<(const value_t lhs, const value_t rhs) noexcept
		{
			static constexpr std::array<std::uint8_t, 8> order = { {
					0 /* null */, 3 /* object */, 4 /* array */, 5 /* string */,
					1 /* boolean */, 2 /* integer */, 2 /* unsigned */, 2 /* float */
				}
			};

			const auto l_index = static_cast<std::size_t>(lhs);
			const auto r_index = static_cast<std::size_t>(rhs);
			return l_index < order.size() and r_index < order.size() and order[l_index] < order[r_index];
		}
	}  // namespace detail
}  // namespace nlohmann


namespace nlohmann
{
	namespace detail
	{
		template<typename BasicJsonType>
		void from_json(const BasicJsonType& j, typename std::nullptr_t& n)
		{
			if (JSON_HEDLEY_UNLIKELY(not j.is_null()))
			{
				JSON_THROW(type_error::create(302, "type must be null, but is " + std::string(j.type_name())));
			}
			n = nullptr;
		}

		// overloads for basic_json template parameters
		template<typename BasicJsonType, typename ArithmeticType,
			enable_if_t<std::is_arithmetic<ArithmeticType>::value and
			not std::is_same<ArithmeticType, typename BasicJsonType::boolean_t>::value,
			int> = 0>
			void get_arithmetic_value(const BasicJsonType& j, ArithmeticType& val)
		{
			switch (static_cast<value_t>(j))
			{
			case value_t::number_unsigned:
			{
				val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::number_unsigned_t*>());
				break;
			}
			case value_t::number_integer:
			{
				val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::number_integer_t*>());
				break;
			}
			case value_t::number_float:
			{
				val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::number_float_t*>());
				break;
			}

			default:
				JSON_THROW(type_error::create(302, "type must be number, but is " + std::string(j.type_name())));
			}
		}

		template<typename BasicJsonType>
		void from_json(const BasicJsonType& j, typename BasicJsonType::boolean_t& b)
		{
			if (JSON_HEDLEY_UNLIKELY(not j.is_boolean()))
			{
				JSON_THROW(type_error::create(302, "type must be boolean, but is " + std::string(j.type_name())));
			}
			b = *j.template get_ptr<const typename BasicJsonType::boolean_t*>();
		}

		template<typename BasicJsonType>
		void from_json(const BasicJsonType& j, typename BasicJsonType::string_t& s)
		{
			if (JSON_HEDLEY_UNLIKELY(not j.is_string()))
			{
				JSON_THROW(type_error::create(302, "type must be string, but is " + std::string(j.type_name())));
			}
			s = *j.template get_ptr<const typename BasicJsonType::string_t*>();
		}

		template <
			typename BasicJsonType, typename ConstructibleStringType,
			enable_if_t <
			is_constructible_string_type<BasicJsonType, ConstructibleStringType>::value and
			not std::is_same<typename BasicJsonType::string_t,
			ConstructibleStringType>::value,
			int > = 0 >
			void from_json(const BasicJsonType& j, ConstructibleStringType& s)
		{
			if (JSON_HEDLEY_UNLIKELY(not j.is_string()))
			{
				JSON_THROW(type_error::create(302, "type must be string, but is " + std::string(j.type_name())));
			}

			s = *j.template get_ptr<const typename BasicJsonType::string_t*>();
		}

		template<typename BasicJsonType>
		void from_json(const BasicJsonType& j, typename BasicJsonType::number_float_t& val)
		{
			get_arithmetic_value(j, val);
		}

		template<typename BasicJsonType>
		void from_json(const BasicJsonType& j, typename BasicJsonType::number_unsigned_t& val)
		{
			get_arithmetic_value(j, val);
		}

		template<typename BasicJsonType>
		void from_json(const BasicJsonType& j, typename BasicJsonType::number_integer_t& val)
		{
			get_arithmetic_value(j, val);
		}

		template<typename BasicJsonType, typename EnumType,
			enable_if_t<std::is_enum<EnumType>::value, int> = 0>
			void from_json(const BasicJsonType& j, EnumType& e)
		{
			typename std::underlying_type<EnumType>::type val;
			get_arithmetic_value(j, val);
			e = static_cast<EnumType>(val);
		}

		// forward_list doesn't have an insert method
		template<typename BasicJsonType, typename T, typename Allocator,
			enable_if_t<std::is_convertible<BasicJsonType, T>::value, int> = 0>
			void from_json(const BasicJsonType& j, std::forward_list<T, Allocator>& l)
		{
			if (JSON_HEDLEY_UNLIKELY(not j.is_array()))
			{
				JSON_THROW(type_error::create(302, "type must be array, but is " + std::string(j.type_name())));
			}
			l.clear();
			std::transform(j.rbegin(), j.rend(),
				std::front_inserter(l), [](const BasicJsonType& i)
				{
					return i.template get<T>();
				});
		}

		// valarray doesn't have an insert method
		template<typename BasicJsonType, typename T,
			enable_if_t<std::is_convertible<BasicJsonType, T>::value, int> = 0>
			void from_json(const BasicJsonType& j, std::valarray<T>& l)
		{
			if (JSON_HEDLEY_UNLIKELY(not j.is_array()))
			{
				JSON_THROW(type_error::create(302, "type must be array, but is " + std::string(j.type_name())));
			}
			l.resize(j.size());
			std::copy(j.m_value.array->begin(), j.m_value.array->end(), std::begin(l));
		}

		template <typename BasicJsonType, typename T, std::size_t N>
		auto from_json(const BasicJsonType& j, T(&arr)[N])
			-> decltype(j.template get<T>(), void())
		{
			for (std::size_t i = 0; i < N; ++i)
			{
				arr[i] = j.at(i).template get<T>();
			}
		}

		template<typename BasicJsonType>
		void from_json_array_impl(const BasicJsonType& j, typename BasicJsonType::array_t& arr, priority_tag<3> /*unused*/)
		{
			arr = *j.template get_ptr<const typename BasicJsonType::array_t*>();
		}

		template <typename BasicJsonType, typename T, std::size_t N>
		auto from_json_array_impl(const BasicJsonType& j, std::array<T, N>& arr,
			priority_tag<2> /*unused*/)
			-> decltype(j.template get<T>(), void())
		{
			for (std::size_t i = 0; i < N; ++i)
			{
				arr[i] = j.at(i).template get<T>();
			}
		}

		template<typename BasicJsonType, typename ConstructibleArrayType>
		auto from_json_array_impl(const BasicJsonType& j, ConstructibleArrayType& arr, priority_tag<1> /*unused*/)
			-> decltype(
				arr.reserve(std::declval<typename ConstructibleArrayType::size_type>()),
				j.template get<typename ConstructibleArrayType::value_type>(),
				void())
		{
			using std::end;

			ConstructibleArrayType ret;
			ret.reserve(j.size());
			std::transform(j.begin(), j.end(),
				std::inserter(ret, end(ret)), [](const BasicJsonType& i)
				{
					// get<BasicJsonType>() returns *this, this won't call a from_json
					// method when value_type is BasicJsonType
					return i.template get<typename ConstructibleArrayType::value_type>();
				});
			arr = std::move(ret);
		}

		template <typename BasicJsonType, typename ConstructibleArrayType>
		void from_json_array_impl(const BasicJsonType& j, ConstructibleArrayType& arr,
			priority_tag<0> /*unused*/)
		{
			using std::end;

			ConstructibleArrayType ret;
			std::transform(
				j.begin(), j.end(), std::inserter(ret, end(ret)),
				[](const BasicJsonType& i)
				{
					// get<BasicJsonType>() returns *this, this won't call a from_json
					// method when value_type is BasicJsonType
					return i.template get<typename ConstructibleArrayType::value_type>();
				});
			arr = std::move(ret);
		}

		template <typename BasicJsonType, typename ConstructibleArrayType,
			enable_if_t <
			is_constructible_array_type<BasicJsonType, ConstructibleArrayType>::value and
			not is_constructible_object_type<BasicJsonType, ConstructibleArrayType>::value and
			not is_constructible_string_type<BasicJsonType, ConstructibleArrayType>::value and
			not is_basic_json<ConstructibleArrayType>::value,
			int > = 0 >

			auto from_json(const BasicJsonType& j, ConstructibleArrayType& arr)
			-> decltype(from_json_array_impl(j, arr, priority_tag<3> {}),
				j.template get<typename ConstructibleArrayType::value_type>(),
				void())
		{
			if (JSON_HEDLEY_UNLIKELY(not j.is_array()))
			{
				JSON_THROW(type_error::create(302, "type must be array, but is " +
					std::string(j.type_name())));
			}

			from_json_array_impl(j, arr, priority_tag<3> {});
		}

		template<typename BasicJsonType, typename ConstructibleObjectType,
			enable_if_t<is_constructible_object_type<BasicJsonType, ConstructibleObjectType>::value, int> = 0>
			void from_json(const BasicJsonType& j, ConstructibleObjectType& obj)
		{
			if (JSON_HEDLEY_UNLIKELY(not j.is_object()))
			{
				JSON_THROW(type_error::create(302, "type must be object, but is " + std::string(j.type_name())));
			}

			ConstructibleObjectType ret;
			auto inner_object = j.template get_ptr<const typename BasicJsonType::object_t*>();
			using value_type = typename ConstructibleObjectType::value_type;
			std::transform(
				inner_object->begin(), inner_object->end(),
				std::inserter(ret, ret.begin()),
				[](typename BasicJsonType::object_t::value_type const& p)
				{
					return value_type(p.first, p.second.template get<typename ConstructibleObjectType::mapped_type>());
				});
			obj = std::move(ret);
		}

		// overload for arithmetic types, not chosen for basic_json template arguments
		// (BooleanType, etc..); note: Is it really necessary to provide explicit
		// overloads for boolean_t etc. in case of a custom BooleanType which is not
		// an arithmetic type?
		template<typename BasicJsonType, typename ArithmeticType,
			enable_if_t <
			std::is_arithmetic<ArithmeticType>::value and
			not std::is_same<ArithmeticType, typename BasicJsonType::number_unsigned_t>::value and
			not std::is_same<ArithmeticType, typename BasicJsonType::number_integer_t>::value and
			not std::is_same<ArithmeticType, typename BasicJsonType::number_float_t>::value and
			not std::is_same<ArithmeticType, typename BasicJsonType::boolean_t>::value,
			int> = 0>
			void from_json(const BasicJsonType& j, ArithmeticType& val)
		{
			switch (static_cast<value_t>(j))
			{
			case value_t::number_unsigned:
			{
				val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::number_unsigned_t*>());
				break;
			}
			case value_t::number_integer:
			{
				val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::number_integer_t*>());
				break;
			}
			case value_t::number_float:
			{
				val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::number_float_t*>());
				break;
			}
			case value_t::boolean:
			{
				val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::boolean_t*>());
				break;
			}

			default:
				JSON_THROW(type_error::create(302, "type must be number, but is " + std::string(j.type_name())));
			}
		}

		template<typename BasicJsonType, typename A1, typename A2>
		void from_json(const BasicJsonType& j, std::pair<A1, A2>& p)
		{
			p = { j.at(0).template get<A1>(), j.at(1).template get<A2>() };
		}

		template<typename BasicJsonType, typename Tuple, std::size_t... Idx>
		void from_json_tuple_impl(const BasicJsonType& j, Tuple& t, index_sequence<Idx...> /*unused*/)
		{
			t = std::make_tuple(j.at(Idx).template get<typename std::tuple_element<Idx, Tuple>::type>()...);
		}

		template<typename BasicJsonType, typename... Args>
		void from_json(const BasicJsonType& j, std::tuple<Args...>& t)
		{
			from_json_tuple_impl(j, t, index_sequence_for<Args...> {});
		}

		template <typename BasicJsonType, typename Key, typename Value, typename Compare, typename Allocator,
			typename = enable_if_t<not std::is_constructible<
			typename BasicJsonType::string_t, Key>::value>>
			void from_json(const BasicJsonType& j, std::map<Key, Value, Compare, Allocator>& m)
		{
			if (JSON_HEDLEY_UNLIKELY(not j.is_array()))
			{
				JSON_THROW(type_error::create(302, "type must be array, but is " + std::string(j.type_name())));
			}
			m.clear();
			for (const auto& p : j)
			{
				if (JSON_HEDLEY_UNLIKELY(not p.is_array()))
				{
					JSON_THROW(type_error::create(302, "type must be array, but is " + std::string(p.type_name())));
				}
				m.emplace(p.at(0).template get<Key>(), p.at(1).template get<Value>());
			}
		}

		template <typename BasicJsonType, typename Key, typename Value, typename Hash, typename KeyEqual, typename Allocator,
			typename = enable_if_t<not std::is_constructible<
			typename BasicJsonType::string_t, Key>::value>>
			void from_json(const BasicJsonType& j, std::unordered_map<Key, Value, Hash, KeyEqual, Allocator>& m)
		{
			if (JSON_HEDLEY_UNLIKELY(not j.is_array()))
			{
				JSON_THROW(type_error::create(302, "type must be array, but is " + std::string(j.type_name())));
			}
			m.clear();
			for (const auto& p : j)
			{
				if (JSON_HEDLEY_UNLIKELY(not p.is_array()))
				{
					JSON_THROW(type_error::create(302, "type must be array, but is " + std::string(p.type_name())));
				}
				m.emplace(p.at(0).template get<Key>(), p.at(1).template get<Value>());
			}
		}

		struct from_json_fn
		{
			template<typename BasicJsonType, typename T>
			auto operator()(const BasicJsonType& j, T& val) const
				noexcept(noexcept(from_json(j, val)))
				-> decltype(from_json(j, val), void())
			{
				return from_json(j, val);
			}
		};
	}  // namespace detail

	/// namespace to hold default `from_json` function
	/// to see why this is required:
	/// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4381.html
	namespace
	{
		constexpr const auto& from_json = detail::static_const<detail::from_json_fn>::value;
	} // namespace
} // namespace nlohmann

// #include <nlohmann/detail/conversions/to_json.hpp>


#include <algorithm> // copy
#include <ciso646> // or, and, not
#include <iterator> // begin, end
#include <string> // string
#include <tuple> // tuple, get
#include <type_traits> // is_same, is_constructible, is_floating_point, is_enum, underlying_type
#include <utility> // move, forward, declval, pair
#include <valarray> // valarray
#include <vector> // vector

// #include <nlohmann/detail/iterators/iteration_proxy.hpp>


#include <cstddef> // size_t
#include <iterator> // input_iterator_tag
#include <string> // string, to_string
#include <tuple> // tuple_size, get, tuple_element

// #include <nlohmann/detail/meta/type_traits.hpp>

// #include <nlohmann/detail/value_t.hpp>


namespace nlohmann
{
	namespace detail
	{
		template <typename IteratorType> class iteration_proxy_value
		{
		public:
			using difference_type = std::ptrdiff_t;
			using value_type = iteration_proxy_value;
			using pointer = value_type*;
			using reference = value_type&;
			using iterator_category = std::input_iterator_tag;

		private:
			/// the iterator
			IteratorType anchor;
			/// an index for arrays (used to create key names)
			std::size_t array_index = 0;
			/// last stringified array index
			mutable std::size_t array_index_last = 0;
			/// a string representation of the array index
			mutable std::string array_index_str = "0";
			/// an empty string (to return a reference for primitive values)
			const std::string empty_str = "";

		public:
			explicit iteration_proxy_value(IteratorType it) noexcept : anchor(it) {}

			/// dereference operator (needed for range-based for)
			iteration_proxy_value& operator*()
			{
				return *this;
			}

			/// increment operator (needed for range-based for)
			iteration_proxy_value& operator++()
			{
				++anchor;
				++array_index;

				return *this;
			}

			/// equality operator (needed for InputIterator)
			bool operator==(const iteration_proxy_value& o) const
			{
				return anchor == o.anchor;
			}

			/// inequality operator (needed for range-based for)
			bool operator!=(const iteration_proxy_value& o) const
			{
				return anchor != o.anchor;
			}

			/// return key of the iterator
			const std::string& key() const
			{
				assert(anchor.m_object != nullptr);

				switch (anchor.m_object->type())
				{
					// use integer array index as key
				case value_t::array:
				{
					if (array_index != array_index_last)
					{
						array_index_str = std::to_string(array_index);
						array_index_last = array_index;
					}
					return array_index_str;
				}

				// use key from the object
				case value_t::object:
					return anchor.key();

					// use an empty key for all primitive types
				default:
					return empty_str;
				}
			}

			/// return value of the iterator
			typename IteratorType::reference value() const
			{
				return anchor.value();
			}
		};

		/// proxy class for the items() function
		template<typename IteratorType> class iteration_proxy
		{
		private:
			/// the container to iterate
			typename IteratorType::reference container;

		public:
			/// construct iteration proxy from a container
			explicit iteration_proxy(typename IteratorType::reference cont) noexcept
				: container(cont) {}

			/// return iterator begin (needed for range-based for)
			iteration_proxy_value<IteratorType> begin() noexcept
			{
				return iteration_proxy_value<IteratorType>(container.begin());
			}

			/// return iterator end (needed for range-based for)
			iteration_proxy_value<IteratorType> end() noexcept
			{
				return iteration_proxy_value<IteratorType>(container.end());
			}
		};
		// Structured Bindings Support
		// For further reference see https://blog.tartanllama.xyz/structured-bindings/
		// And see https://github.com/nlohmann/json/pull/1391
		template <std::size_t N, typename IteratorType, enable_if_t<N == 0, int> = 0>
		auto get(const nlohmann::detail::iteration_proxy_value<IteratorType>& i) -> decltype(i.key())
		{
			return i.key();
		}
		// Structured Bindings Support
		// For further reference see https://blog.tartanllama.xyz/structured-bindings/
		// And see https://github.com/nlohmann/json/pull/1391
		template <std::size_t N, typename IteratorType, enable_if_t<N == 1, int> = 0>
		auto get(const nlohmann::detail::iteration_proxy_value<IteratorType>& i) -> decltype(i.value())
		{
			return i.value();
		}
	}  // namespace detail
}  // namespace nlohmann

// The Addition to the STD Namespace is required to add
// Structured Bindings Support to the iteration_proxy_value class
// For further reference see https://blog.tartanllama.xyz/structured-bindings/
// And see https://github.com/nlohmann/json/pull/1391
namespace std
{
#if defined(__clang__)
	// Fix: https://github.com/nlohmann/json/issues/1401
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmismatched-tags"
#endif
	template <typename IteratorType>
	class tuple_size<::nlohmann::detail::iteration_proxy_value<IteratorType>>
		: public std::integral_constant<std::size_t, 2> {};

	template <std::size_t N, typename IteratorType>
	class tuple_element<N, ::nlohmann::detail::iteration_proxy_value<IteratorType >>
	{
	public:
		using type = decltype(
			get<N>(std::declval <
				::nlohmann::detail::iteration_proxy_value<IteratorType >> ()));
	};
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
} // namespace std

// #include <nlohmann/detail/meta/cpp_future.hpp>

// #include <nlohmann/detail/meta/type_traits.hpp>

// #include <nlohmann/detail/value_t.hpp>


namespace nlohmann
{
	namespace detail
	{
		//////////////////
		// constructors //
		//////////////////

		template<value_t> struct external_constructor;

		template<>
		struct external_constructor<value_t::boolean>
		{
			template<typename BasicJsonType>
			static void construct(BasicJsonType& j, typename BasicJsonType::boolean_t b) noexcept
			{
				j.m_type = value_t::boolean;
				j.m_value = b;
				j.assert_invariant();
			}
		};

		template<>
		struct external_constructor<value_t::string>
		{
			template<typename BasicJsonType>
			static void construct(BasicJsonType& j, const typename BasicJsonType::string_t& s)
			{
				j.m_type = value_t::string;
				j.m_value = s;
				j.assert_invariant();
			}

			template<typename BasicJsonType>
			static void construct(BasicJsonType& j, typename BasicJsonType::string_t&& s)
			{
				j.m_type = value_t::string;
				j.m_value = std::move(s);
				j.assert_invariant();
			}

			template<typename BasicJsonType, typename CompatibleStringType,
				enable_if_t<not std::is_same<CompatibleStringType, typename BasicJsonType::string_t>::value,
				int> = 0>
				static void construct(BasicJsonType& j, const CompatibleStringType& str)
			{
				j.m_type = value_t::string;
				j.m_value.string = j.template create<typename BasicJsonType::string_t>(str);
				j.assert_invariant();
			}
		};

		template<>
		struct external_constructor<value_t::number_float>
		{
			template<typename BasicJsonType>
			static void construct(BasicJsonType& j, typename BasicJsonType::number_float_t val) noexcept
			{
				j.m_type = value_t::number_float;
				j.m_value = val;
				j.assert_invariant();
			}
		};

		template<>
		struct external_constructor<value_t::number_unsigned>
		{
			template<typename BasicJsonType>
			static void construct(BasicJsonType& j, typename BasicJsonType::number_unsigned_t val) noexcept
			{
				j.m_type = value_t::number_unsigned;
				j.m_value = val;
				j.assert_invariant();
			}
		};

		template<>
		struct external_constructor<value_t::number_integer>
		{
			template<typename BasicJsonType>
			static void construct(BasicJsonType& j, typename BasicJsonType::number_integer_t val) noexcept
			{
				j.m_type = value_t::number_integer;
				j.m_value = val;
				j.assert_invariant();
			}
		};

		template<>
		struct external_constructor<value_t::array>
		{
			template<typename BasicJsonType>
			static void construct(BasicJsonType& j, const typename BasicJsonType::array_t& arr)
			{
				j.m_type = value_t::array;
				j.m_value = arr;
				j.assert_invariant();
			}

			template<typename BasicJsonType>
			static void construct(BasicJsonType& j, typename BasicJsonType::array_t&& arr)
			{
				j.m_type = value_t::array;
				j.m_value = std::move(arr);
				j.assert_invariant();
			}

			template<typename BasicJsonType, typename CompatibleArrayType,
				enable_if_t<not std::is_same<CompatibleArrayType, typename BasicJsonType::array_t>::value,
				int> = 0>
				static void construct(BasicJsonType& j, const CompatibleArrayType& arr)
			{
				using std::begin;
				using std::end;
				j.m_type = value_t::array;
				j.m_value.array = j.template create<typename BasicJsonType::array_t>(begin(arr), end(arr));
				j.assert_invariant();
			}

			template<typename BasicJsonType>
			static void construct(BasicJsonType& j, const std::vector<bool>& arr)
			{
				j.m_type = value_t::array;
				j.m_value = value_t::array;
				j.m_value.array->reserve(arr.size());
				for (const bool x : arr)
				{
					j.m_value.array->push_back(x);
				}
				j.assert_invariant();
			}

			template<typename BasicJsonType, typename T,
				enable_if_t<std::is_convertible<T, BasicJsonType>::value, int> = 0>
				static void construct(BasicJsonType& j, const std::valarray<T>& arr)
			{
				j.m_type = value_t::array;
				j.m_value = value_t::array;
				j.m_value.array->resize(arr.size());
				if (arr.size() > 0)
				{
					std::copy(std::begin(arr), std::end(arr), j.m_value.array->begin());
				}
				j.assert_invariant();
			}
		};

		template<>
		struct external_constructor<value_t::object>
		{
			template<typename BasicJsonType>
			static void construct(BasicJsonType& j, const typename BasicJsonType::object_t& obj)
			{
				j.m_type = value_t::object;
				j.m_value = obj;
				j.assert_invariant();
			}

			template<typename BasicJsonType>
			static void construct(BasicJsonType& j, typename BasicJsonType::object_t&& obj)
			{
				j.m_type = value_t::object;
				j.m_value = std::move(obj);
				j.assert_invariant();
			}

			template<typename BasicJsonType, typename CompatibleObjectType,
				enable_if_t<not std::is_same<CompatibleObjectType, typename BasicJsonType::object_t>::value, int> = 0>
				static void construct(BasicJsonType& j, const CompatibleObjectType& obj)
			{
				using std::begin;
				using std::end;

				j.m_type = value_t::object;
				j.m_value.object = j.template create<typename BasicJsonType::object_t>(begin(obj), end(obj));
				j.assert_invariant();
			}
		};

		/////////////
		// to_json //
		/////////////

		template<typename BasicJsonType, typename T,
			enable_if_t<std::is_same<T, typename BasicJsonType::boolean_t>::value, int> = 0>
			void to_json(BasicJsonType& j, T b) noexcept
		{
			external_constructor<value_t::boolean>::construct(j, b);
		}

		template<typename BasicJsonType, typename CompatibleString,
			enable_if_t<std::is_constructible<typename BasicJsonType::string_t, CompatibleString>::value, int> = 0>
			void to_json(BasicJsonType& j, const CompatibleString& s)
		{
			external_constructor<value_t::string>::construct(j, s);
		}

		template<typename BasicJsonType>
		void to_json(BasicJsonType& j, typename BasicJsonType::string_t&& s)
		{
			external_constructor<value_t::string>::construct(j, std::move(s));
		}

		template<typename BasicJsonType, typename FloatType,
			enable_if_t<std::is_floating_point<FloatType>::value, int> = 0>
			void to_json(BasicJsonType& j, FloatType val) noexcept
		{
			external_constructor<value_t::number_float>::construct(j, static_cast<typename BasicJsonType::number_float_t>(val));
		}

		template<typename BasicJsonType, typename CompatibleNumberUnsignedType,
			enable_if_t<is_compatible_integer_type<typename BasicJsonType::number_unsigned_t, CompatibleNumberUnsignedType>::value, int> = 0>
			void to_json(BasicJsonType& j, CompatibleNumberUnsignedType val) noexcept
		{
			external_constructor<value_t::number_unsigned>::construct(j, static_cast<typename BasicJsonType::number_unsigned_t>(val));
		}

		template<typename BasicJsonType, typename CompatibleNumberIntegerType,
			enable_if_t<is_compatible_integer_type<typename BasicJsonType::number_integer_t, CompatibleNumberIntegerType>::value, int> = 0>
			void to_json(BasicJsonType& j, CompatibleNumberIntegerType val) noexcept
		{
			external_constructor<value_t::number_integer>::construct(j, static_cast<typename BasicJsonType::number_integer_t>(val));
		}

		template<typename BasicJsonType, typename EnumType,
			enable_if_t<std::is_enum<EnumType>::value, int> = 0>
			void to_json(BasicJsonType& j, EnumType e) noexcept
		{
			using underlying_type = typename std::underlying_type<EnumType>::type;
			external_constructor<value_t::number_integer>::construct(j, static_cast<underlying_type>(e));
		}

		template<typename BasicJsonType>
		void to_json(BasicJsonType& j, const std::vector<bool>& e)
		{
			external_constructor<value_t::array>::construct(j, e);
		}

		template <typename BasicJsonType, typename CompatibleArrayType,
			enable_if_t<is_compatible_array_type<BasicJsonType,
			CompatibleArrayType>::value and
			not is_compatible_object_type<
			BasicJsonType, CompatibleArrayType>::value and
			not is_compatible_string_type<BasicJsonType, CompatibleArrayType>::value and
			not is_basic_json<CompatibleArrayType>::value,
			int> = 0>
			void to_json(BasicJsonType& j, const CompatibleArrayType& arr)
		{
			external_constructor<value_t::array>::construct(j, arr);
		}

		template<typename BasicJsonType, typename T,
			enable_if_t<std::is_convertible<T, BasicJsonType>::value, int> = 0>
			void to_json(BasicJsonType& j, const std::valarray<T>& arr)
		{
			external_constructor<value_t::array>::construct(j, std::move(arr));
		}

		template<typename BasicJsonType>
		void to_json(BasicJsonType& j, typename BasicJsonType::array_t&& arr)
		{
			external_constructor<value_t::array>::construct(j, std::move(arr));
		}

		template<typename BasicJsonType, typename CompatibleObjectType,
			enable_if_t<is_compatible_object_type<BasicJsonType, CompatibleObjectType>::value and not is_basic_json<CompatibleObjectType>::value, int> = 0>
			void to_json(BasicJsonType& j, const CompatibleObjectType& obj)
		{
			external_constructor<value_t::object>::construct(j, obj);
		}

		template<typename BasicJsonType>
		void to_json(BasicJsonType& j, typename BasicJsonType::object_t&& obj)
		{
			external_constructor<value_t::object>::construct(j, std::move(obj));
		}

		template <
			typename BasicJsonType, typename T, std::size_t N,
			enable_if_t<not std::is_constructible<typename BasicJsonType::string_t,
			const T(&)[N]>::value,
			int> = 0 >
			void to_json(BasicJsonType& j, const T(&arr)[N])
		{
			external_constructor<value_t::array>::construct(j, arr);
		}

		template<typename BasicJsonType, typename... Args>
		void to_json(BasicJsonType& j, const std::pair<Args...>& p)
		{
			j = { p.first, p.second };
		}

		// for https://github.com/nlohmann/json/pull/1134
		template < typename BasicJsonType, typename T,
			enable_if_t<std::is_same<T, iteration_proxy_value<typename BasicJsonType::iterator>>::value, int> = 0>
			void to_json(BasicJsonType& j, const T& b)
		{
			j = { {b.key(), b.value()} };
		}

		template<typename BasicJsonType, typename Tuple, std::size_t... Idx>
		void to_json_tuple_impl(BasicJsonType& j, const Tuple& t, index_sequence<Idx...> /*unused*/)
		{
			j = { std::get<Idx>(t)... };
		}

		template<typename BasicJsonType, typename... Args>
		void to_json(BasicJsonType& j, const std::tuple<Args...>& t)
		{
			to_json_tuple_impl(j, t, index_sequence_for<Args...> {});
		}

		struct to_json_fn
		{
			template<typename BasicJsonType, typename T>
			auto operator()(BasicJsonType& j, T&& val) const noexcept(noexcept(to_json(j, std::forward<T>(val))))
				-> decltype(to_json(j, std::forward<T>(val)), void())
			{
				return to_json(j, std::forward<T>(val));
			}
		};
	}  // namespace detail

	/// namespace to hold default `to_json` function
	namespace
	{
		constexpr const auto& to_json = detail::static_const<detail::to_json_fn>::value;
	} // namespace
} // namespace nlohmann


namespace nlohmann
{

	template<typename, typename>
	struct adl_serializer
	{
		/*!
		@brief convert a JSON value to any value type
		This function is usually called by the `get()` function of the
		@ref basic_json class (either explicit or via conversion operators).
		@param[in] j        JSON value to read from
		@param[in,out] val  value to write to
		*/
		template<typename BasicJsonType, typename ValueType>
		static auto from_json(BasicJsonType&& j, ValueType& val) noexcept(
			noexcept(::nlohmann::from_json(std::forward<BasicJsonType>(j), val)))
			-> decltype(::nlohmann::from_json(std::forward<BasicJsonType>(j), val), void())
		{
			::nlohmann::from_json(std::forward<BasicJsonType>(j), val);
		}

		/*!
		@brief convert any value type to a JSON value
		This function is usually called by the constructors of the @ref basic_json
		class.
		@param[in,out] j  JSON value to write to
		@param[in] val    value to read from
		*/
		template <typename BasicJsonType, typename ValueType>
		static auto to_json(BasicJsonType& j, ValueType&& val) noexcept(
			noexcept(::nlohmann::to_json(j, std::forward<ValueType>(val))))
			-> decltype(::nlohmann::to_json(j, std::forward<ValueType>(val)), void())
		{
			::nlohmann::to_json(j, std::forward<ValueType>(val));
		}
	};

}  // namespace nlohmann

// #include <nlohmann/detail/conversions/from_json.hpp>

// #include <nlohmann/detail/conversions/to_json.hpp>

// #include <nlohmann/detail/exceptions.hpp>

// #include <nlohmann/detail/input/binary_reader.hpp>


#include <algorithm> // generate_n
#include <array> // array
#include <cassert> // assert
#include <cmath> // ldexp
#include <cstddef> // size_t
#include <cstdint> // uint8_t, uint16_t, uint32_t, uint64_t
#include <cstdio> // snprintf
#include <cstring> // memcpy
#include <iterator> // back_inserter
#include <limits> // numeric_limits
#include <string> // char_traits, string
#include <utility> // make_pair, move

// #include <nlohmann/detail/exceptions.hpp>

// #include <nlohmann/detail/input/input_adapters.hpp>


#include <array> // array
#include <cassert> // assert
#include <cstddef> // size_t
#include <cstdio> //FILE *
#include <cstring> // strlen
#include <istream> // istream
#include <iterator> // begin, end, iterator_traits, random_access_iterator_tag, distance, next
#include <memory> // shared_ptr, make_shared, addressof
#include <numeric> // accumulate
#include <string> // string, char_traits
#include <type_traits> // enable_if, is_base_of, is_pointer, is_integral, remove_pointer
#include <utility> // pair, declval

// #include <nlohmann/detail/iterators/iterator_traits.hpp>

// #include <nlohmann/detail/macro_scope.hpp>


namespace nlohmann
{
	namespace detail
	{
		/// the supported input formats
		enum class input_format_t { json, cbor, msgpack, ubjson, bson };

		////////////////////
		// input adapters //
		////////////////////

		/*!
		@brief abstract input adapter interface
		Produces a stream of std::char_traits<char>::int_type characters from a
		std::istream, a buffer, or some other input type. Accepts the return of
		exactly one non-EOF character for future input. The int_type characters
		returned consist of all valid char values as positive values (typically
		unsigned char), plus an EOF value outside that range, specified by the value
		of the function std::char_traits<char>::eof(). This value is typically -1, but
		could be any arbitrary value which is not a valid char value.
		*/
		struct input_adapter_protocol
		{
			/// get a character [0,255] or std::char_traits<char>::eof().
			virtual std::char_traits<char>::int_type get_character() = 0;
			virtual ~input_adapter_protocol() = default;
		};

		/// a type to simplify interfaces
		using input_adapter_t = std::shared_ptr<input_adapter_protocol>;

		/*!
		Input adapter for stdio file access. This adapter read only 1 byte and do not use any
		 buffer. This adapter is a very low level adapter.
		*/
		class file_input_adapter : public input_adapter_protocol
		{
		public:
			JSON_HEDLEY_NON_NULL(2)
				explicit file_input_adapter(std::FILE* f)  noexcept
				: m_file(f)
			{}

			// make class move-only
			file_input_adapter(const file_input_adapter&) = delete;
			file_input_adapter(file_input_adapter&&) = default;
			file_input_adapter& operator=(const file_input_adapter&) = delete;
			file_input_adapter& operator=(file_input_adapter&&) = default;
			~file_input_adapter() override = default;

			std::char_traits<char>::int_type get_character() noexcept override
			{
				return std::fgetc(m_file);
			}

		private:
			/// the file pointer to read from
			std::FILE* m_file;
		};


		/*!
		Input adapter for a (caching) istream. Ignores a UFT Byte Order Mark at
		beginning of input. Does not support changing the underlying std::streambuf
		in mid-input. Maintains underlying std::istream and std::streambuf to support
		subsequent use of standard std::istream operations to process any input
		characters following those used in parsing the JSON input.  Clears the
		std::istream flags; any input errors (e.g., EOF) will be detected by the first
		subsequent call for input from the std::istream.
		*/
		class input_stream_adapter : public input_adapter_protocol
		{
		public:
			~input_stream_adapter() override
			{
				// clear stream flags; we use underlying streambuf I/O, do not
				// maintain ifstream flags, except eof
				is.clear(is.rdstate() & std::ios::eofbit);
			}

			explicit input_stream_adapter(std::istream& i)
				: is(i), sb(*i.rdbuf())
			{}

			// delete because of pointer members
			input_stream_adapter(const input_stream_adapter&) = delete;
			input_stream_adapter& operator=(input_stream_adapter&) = delete;
			input_stream_adapter(input_stream_adapter&&) = delete;
			input_stream_adapter& operator=(input_stream_adapter&&) = delete;

			// std::istream/std::streambuf use std::char_traits<char>::to_int_type, to
			// ensure that std::char_traits<char>::eof() and the character 0xFF do not
			// end up as the same value, eg. 0xFFFFFFFF.
			std::char_traits<char>::int_type get_character() override
			{
				auto res = sb.sbumpc();
				// set eof manually, as we don't use the istream interface.
				if (res == EOF)
				{
					is.clear(is.rdstate() | std::ios::eofbit);
				}
				return res;
			}

		private:
			/// the associated input stream
			std::istream& is;
			std::streambuf& sb;
		};

		/// input adapter for buffer input
		class input_buffer_adapter : public input_adapter_protocol
		{
		public:
			input_buffer_adapter(const char* b, const std::size_t l) noexcept
				: cursor(b), limit(b == nullptr ? nullptr : (b + l))
			{}

			// delete because of pointer members
			input_buffer_adapter(const input_buffer_adapter&) = delete;
			input_buffer_adapter& operator=(input_buffer_adapter&) = delete;
			input_buffer_adapter(input_buffer_adapter&&) = delete;
			input_buffer_adapter& operator=(input_buffer_adapter&&) = delete;
			~input_buffer_adapter() override = default;

			std::char_traits<char>::int_type get_character() noexcept override
			{
				if (JSON_HEDLEY_LIKELY(cursor < limit))
				{
					assert(cursor != nullptr and limit != nullptr);
					return std::char_traits<char>::to_int_type(*(cursor++));
				}

				return std::char_traits<char>::eof();
			}

		private:
			/// pointer to the current character
			const char* cursor;
			/// pointer past the last character
			const char* const limit;
		};

		template<typename WideStringType, size_t T>
		struct wide_string_input_helper
		{
			// UTF-32
			static void fill_buffer(const WideStringType& str,
				size_t& current_wchar,
				std::array<std::char_traits<char>::int_type, 4>& utf8_bytes,
				size_t& utf8_bytes_index,
				size_t& utf8_bytes_filled)
			{
				utf8_bytes_index = 0;

				if (current_wchar == str.size())
				{
					utf8_bytes[0] = std::char_traits<char>::eof();
					utf8_bytes_filled = 1;
				}
				else
				{
					// get the current character
					const auto wc = static_cast<unsigned int>(str[current_wchar++]);

					// UTF-32 to UTF-8 encoding
					if (wc < 0x80)
					{
						utf8_bytes[0] = static_cast<std::char_traits<char>::int_type>(wc);
						utf8_bytes_filled = 1;
					}
					else if (wc <= 0x7FF)
					{
						utf8_bytes[0] = static_cast<std::char_traits<char>::int_type>(0xC0u | ((wc >> 6u) & 0x1Fu));
						utf8_bytes[1] = static_cast<std::char_traits<char>::int_type>(0x80u | (wc & 0x3Fu));
						utf8_bytes_filled = 2;
					}
					else if (wc <= 0xFFFF)
					{
						utf8_bytes[0] = static_cast<std::char_traits<char>::int_type>(0xE0u | ((wc >> 12u) & 0x0Fu));
						utf8_bytes[1] = static_cast<std::char_traits<char>::int_type>(0x80u | ((wc >> 6u) & 0x3Fu));
						utf8_bytes[2] = static_cast<std::char_traits<char>::int_type>(0x80u | (wc & 0x3Fu));
						utf8_bytes_filled = 3;
					}
					else if (wc <= 0x10FFFF)
					{
						utf8_bytes[0] = static_cast<std::char_traits<char>::int_type>(0xF0u | ((wc >> 18u) & 0x07u));
						utf8_bytes[1] = static_cast<std::char_traits<char>::int_type>(0x80u | ((wc >> 12u) & 0x3Fu));
						utf8_bytes[2] = static_cast<std::char_traits<char>::int_type>(0x80u | ((wc >> 6u) & 0x3Fu));
						utf8_bytes[3] = static_cast<std::char_traits<char>::int_type>(0x80u | (wc & 0x3Fu));
						utf8_bytes_filled = 4;
					}
					else
					{
						// unknown character
						utf8_bytes[0] = static_cast<std::char_traits<char>::int_type>(wc);
						utf8_bytes_filled = 1;
					}
				}
			}
		};

		template<typename WideStringType>
		struct wide_string_input_helper<WideStringType, 2>
		{
			// UTF-16
			static void fill_buffer(const WideStringType& str,
				size_t& current_wchar,
				std::array<std::char_traits<char>::int_type, 4>& utf8_bytes,
				size_t& utf8_bytes_index,
				size_t& utf8_bytes_filled)
			{
				utf8_bytes_index = 0;

				if (current_wchar == str.size())
				{
					utf8_bytes[0] = std::char_traits<char>::eof();
					utf8_bytes_filled = 1;
				}
				else
				{
					// get the current character
					const auto wc = static_cast<unsigned int>(str[current_wchar++]);

					// UTF-16 to UTF-8 encoding
					if (wc < 0x80)
					{
						utf8_bytes[0] = static_cast<std::char_traits<char>::int_type>(wc);
						utf8_bytes_filled = 1;
					}
					else if (wc <= 0x7FF)
					{
						utf8_bytes[0] = static_cast<std::char_traits<char>::int_type>(0xC0u | ((wc >> 6u)));
						utf8_bytes[1] = static_cast<std::char_traits<char>::int_type>(0x80u | (wc & 0x3Fu));
						utf8_bytes_filled = 2;
					}
					else if (0xD800 > wc or wc >= 0xE000)
					{
						utf8_bytes[0] = static_cast<std::char_traits<char>::int_type>(0xE0u | ((wc >> 12u)));
						utf8_bytes[1] = static_cast<std::char_traits<char>::int_type>(0x80u | ((wc >> 6u) & 0x3Fu));
						utf8_bytes[2] = static_cast<std::char_traits<char>::int_type>(0x80u | (wc & 0x3Fu));
						utf8_bytes_filled = 3;
					}
					else
					{
						if (current_wchar < str.size())
						{
							const auto wc2 = static_cast<unsigned int>(str[current_wchar++]);
							const auto charcode = 0x10000u + (((wc & 0x3FFu) << 10u) | (wc2 & 0x3FFu));
							utf8_bytes[0] = static_cast<std::char_traits<char>::int_type>(0xF0u | (charcode >> 18u));
							utf8_bytes[1] = static_cast<std::char_traits<char>::int_type>(0x80u | ((charcode >> 12u) & 0x3Fu));
							utf8_bytes[2] = static_cast<std::char_traits<char>::int_type>(0x80u | ((charcode >> 6u) & 0x3Fu));
							utf8_bytes[3] = static_cast<std::char_traits<char>::int_type>(0x80u | (charcode & 0x3Fu));
							utf8_bytes_filled = 4;
						}
						else
						{
							// unknown character
							++current_wchar;
							utf8_bytes[0] = static_cast<std::char_traits<char>::int_type>(wc);
							utf8_bytes_filled = 1;
						}
					}
				}
			}
		};

		template<typename WideStringType>
		class wide_string_input_adapter : public input_adapter_protocol
		{
		public:
			explicit wide_string_input_adapter(const WideStringType& w) noexcept
				: str(w)
			{}

			std::char_traits<char>::int_type get_character() noexcept override
			{
				// check if buffer needs to be filled
				if (utf8_bytes_index == utf8_bytes_filled)
				{
					fill_buffer<sizeof(typename WideStringType::value_type)>();

					assert(utf8_bytes_filled > 0);
					assert(utf8_bytes_index == 0);
				}

				// use buffer
				assert(utf8_bytes_filled > 0);
				assert(utf8_bytes_index < utf8_bytes_filled);
				return utf8_bytes[utf8_bytes_index++];
			}

		private:
			template<size_t T>
			void fill_buffer()
			{
				wide_string_input_helper<WideStringType, T>::fill_buffer(str, current_wchar, utf8_bytes, utf8_bytes_index, utf8_bytes_filled);
			}

			/// the wstring to process
			const WideStringType& str;

			/// index of the current wchar in str
			std::size_t current_wchar = 0;

			/// a buffer for UTF-8 bytes
			std::array<std::char_traits<char>::int_type, 4> utf8_bytes = { {0, 0, 0, 0} };

			/// index to the utf8_codes array for the next valid byte
			std::size_t utf8_bytes_index = 0;
			/// number of valid bytes in the utf8_codes array
			std::size_t utf8_bytes_filled = 0;
		};

		class input_adapter
		{
		public:
			// native support
			JSON_HEDLEY_NON_NULL(2)
				input_adapter(std::FILE* file)
				: ia(std::make_shared<file_input_adapter>(file)) {}
			/// input adapter for input stream
			input_adapter(std::istream& i)
				: ia(std::make_shared<input_stream_adapter>(i)) {}

			/// input adapter for input stream
			input_adapter(std::istream&& i)
				: ia(std::make_shared<input_stream_adapter>(i)) {}

			input_adapter(const std::wstring& ws)
				: ia(std::make_shared<wide_string_input_adapter<std::wstring>>(ws)) {}

			input_adapter(const std::u16string& ws)
				: ia(std::make_shared<wide_string_input_adapter<std::u16string>>(ws)) {}

			input_adapter(const std::u32string& ws)
				: ia(std::make_shared<wide_string_input_adapter<std::u32string>>(ws)) {}

			/// input adapter for buffer
			template<typename CharT,
				typename std::enable_if<
				std::is_pointer<CharT>::value and
				std::is_integral<typename std::remove_pointer<CharT>::type>::value and
				sizeof(typename std::remove_pointer<CharT>::type) == 1,
				int>::type = 0>
				input_adapter(CharT b, std::size_t l)
				: ia(std::make_shared<input_buffer_adapter>(reinterpret_cast<const char*>(b), l)) {}

			// derived support

			/// input adapter for string literal
			template<typename CharT,
				typename std::enable_if<
				std::is_pointer<CharT>::value and
				std::is_integral<typename std::remove_pointer<CharT>::type>::value and
				sizeof(typename std::remove_pointer<CharT>::type) == 1,
				int>::type = 0>
				input_adapter(CharT b)
				: input_adapter(reinterpret_cast<const char*>(b),
					std::strlen(reinterpret_cast<const char*>(b))) {}

			/// input adapter for iterator range with contiguous storage
			template<class IteratorType,
				typename std::enable_if<
				std::is_same<typename iterator_traits<IteratorType>::iterator_category, std::random_access_iterator_tag>::value,
				int>::type = 0>
				input_adapter(IteratorType first, IteratorType last)
			{
#ifndef NDEBUG
				// assertion to check that the iterator range is indeed contiguous,
				// see http://stackoverflow.com/a/35008842/266378 for more discussion
				const auto is_contiguous = std::accumulate(
					first, last, std::pair<bool, int>(true, 0),
					[&first](std::pair<bool, int> res, decltype(*first) val)
					{
						res.first &= (val == *(std::next(std::addressof(*first), res.second++)));
						return res;
					}).first;
				assert(is_contiguous);
#endif

				// assertion to check that each element is 1 byte long
				static_assert(
					sizeof(typename iterator_traits<IteratorType>::value_type) == 1,
					"each element in the iterator range must have the size of 1 byte");

				const auto len = static_cast<size_t>(std::distance(first, last));
				if (JSON_HEDLEY_LIKELY(len > 0))
				{
					// there is at least one element: use the address of first
					ia = std::make_shared<input_buffer_adapter>(reinterpret_cast<const char*>(&(*first)), len);
				}
				else
				{
					// the address of first cannot be used: use nullptr
					ia = std::make_shared<input_buffer_adapter>(nullptr, len);
				}
			}

			/// input adapter for array
			template<class T, std::size_t N>
			input_adapter(T(&array)[N])
				: input_adapter(std::begin(array), std::end(array)) {}

			/// input adapter for contiguous container
			template<class ContiguousContainer, typename
				std::enable_if<not std::is_pointer<ContiguousContainer>::value and
				std::is_base_of<std::random_access_iterator_tag, typename iterator_traits<decltype(std::begin(std::declval<ContiguousContainer const>()))>::iterator_category>::value,
				int>::type = 0>
				input_adapter(const ContiguousContainer& c)
				: input_adapter(std::begin(c), std::end(c)) {}

			operator input_adapter_t()
			{
				return ia;
			}

		private:
			/// the actual adapter
			input_adapter_t ia = nullptr;
		};
	}  // namespace detail
}  // namespace nlohmann

// #include <nlohmann/detail/input/json_sax.hpp>


#include <cassert> // assert
#include <cstddef>
#include <string> // string
#include <utility> // move
#include <vector> // vector

// #include <nlohmann/detail/exceptions.hpp>

// #include <nlohmann/detail/macro_scope.hpp>


namespace nlohmann
{

	/*!
	@brief SAX interface
	This class describes the SAX interface used by @ref nlohmann::json::sax_parse.
	Each function is called in different situations while the input is parsed. The
	boolean return value informs the parser whether to continue processing the
	input.
	*/
	template<typename BasicJsonType>
	struct json_sax
	{
		/// type for (signed) integers
		using number_integer_t = typename BasicJsonType::number_integer_t;
		/// type for unsigned integers
		using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
		/// type for floating-point numbers
		using number_float_t = typename BasicJsonType::number_float_t;
		/// type for strings
		using string_t = typename BasicJsonType::string_t;

		/*!
		@brief a null value was read
		@return whether parsing should proceed
		*/
		virtual bool null() = 0;

		/*!
		@brief a boolean value was read
		@param[in] val  boolean value
		@return whether parsing should proceed
		*/
		virtual bool boolean(bool val) = 0;

		/*!
		@brief an integer number was read
		@param[in] val  integer value
		@return whether parsing should proceed
		*/
		virtual bool number_integer(number_integer_t val) = 0;

		/*!
		@brief an unsigned integer number was read
		@param[in] val  unsigned integer value
		@return whether parsing should proceed
		*/
		virtual bool number_unsigned(number_unsigned_t val) = 0;

		/*!
		@brief an floating-point number was read
		@param[in] val  floating-point value
		@param[in] s    raw token value
		@return whether parsing should proceed
		*/
		virtual bool number_float(number_float_t val, const string_t& s) = 0;

		/*!
		@brief a string was read
		@param[in] val  string value
		@return whether parsing should proceed
		@note It is safe to move the passed string.
		*/
		virtual bool string(string_t& val) = 0;

		/*!
		@brief the beginning of an object was read
		@param[in] elements  number of object elements or -1 if unknown
		@return whether parsing should proceed
		@note binary formats may report the number of elements
		*/
		virtual bool start_object(std::size_t elements) = 0;

		/*!
		@brief an object key was read
		@param[in] val  object key
		@return whether parsing should proceed
		@note It is safe to move the passed string.
		*/
		virtual bool key(string_t& val) = 0;

		/*!
		@brief the end of an object was read
		@return whether parsing should proceed
		*/
		virtual bool end_object() = 0;

		/*!
		@brief the beginning of an array was read
		@param[in] elements  number of array elements or -1 if unknown
		@return whether parsing should proceed
		@note binary formats may report the number of elements
		*/
		virtual bool start_array(std::size_t elements) = 0;

		/*!
		@brief the end of an array was read
		@return whether parsing should proceed
		*/
		virtual bool end_array() = 0;

		/*!
		@brief a parse error occurred
		@param[in] position    the position in the input where the error occurs
		@param[in] last_token  the last read token
		@param[in] ex          an exception object describing the error
		@return whether parsing should proceed (must return false)
		*/
		virtual bool parse_error(std::size_t position,
			const std::string& last_token,
			const detail::exception& ex) = 0;

		virtual ~json_sax() = default;
	};


	namespace detail
	{
		/*!
		@brief SAX implementation to create a JSON value from SAX events
		This class implements the @ref json_sax interface and processes the SAX events
		to create a JSON value which makes it basically a DOM parser. The structure or
		hierarchy of the JSON value is managed by the stack `ref_stack` which contains
		a pointer to the respective array or object for each recursion depth.
		After successful parsing, the value that is passed by reference to the
		constructor contains the parsed value.
		@tparam BasicJsonType  the JSON type
		*/
		template<typename BasicJsonType>
		class json_sax_dom_parser
		{
		public:
			using number_integer_t = typename BasicJsonType::number_integer_t;
			using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
			using number_float_t = typename BasicJsonType::number_float_t;
			using string_t = typename BasicJsonType::string_t;

			/*!
			@param[in, out] r  reference to a JSON value that is manipulated while
							   parsing
			@param[in] allow_exceptions_  whether parse errors yield exceptions
			*/
			explicit json_sax_dom_parser(BasicJsonType& r, const bool allow_exceptions_ = true)
				: root(r), allow_exceptions(allow_exceptions_)
			{}

			// make class move-only
			json_sax_dom_parser(const json_sax_dom_parser&) = delete;
			json_sax_dom_parser(json_sax_dom_parser&&) = default;
			json_sax_dom_parser& operator=(const json_sax_dom_parser&) = delete;
			json_sax_dom_parser& operator=(json_sax_dom_parser&&) = default;
			~json_sax_dom_parser() = default;

			bool null()
			{
				handle_value(nullptr);
				return true;
			}

			bool boolean(bool val)
			{
				handle_value(val);
				return true;
			}

			bool number_integer(number_integer_t val)
			{
				handle_value(val);
				return true;
			}

			bool number_unsigned(number_unsigned_t val)
			{
				handle_value(val);
				return true;
			}

			bool number_float(number_float_t val, const string_t& /*unused*/)
			{
				handle_value(val);
				return true;
			}

			bool string(string_t& val)
			{
				handle_value(val);
				return true;
			}

			bool start_object(std::size_t len)
			{
				ref_stack.push_back(handle_value(BasicJsonType::value_t::object));

				if (JSON_HEDLEY_UNLIKELY(len != std::size_t(-1) and len > ref_stack.back()->max_size()))
				{
					JSON_THROW(out_of_range::create(408,
						"excessive object size: " + std::to_string(len)));
				}

				return true;
			}

			bool key(string_t& val)
			{
				// add null at given key and store the reference for later
				object_element = &(ref_stack.back()->m_value.object->operator[](val));
				return true;
			}

			bool end_object()
			{
				ref_stack.pop_back();
				return true;
			}

			bool start_array(std::size_t len)
			{
				ref_stack.push_back(handle_value(BasicJsonType::value_t::array));

				if (JSON_HEDLEY_UNLIKELY(len != std::size_t(-1) and len > ref_stack.back()->max_size()))
				{
					JSON_THROW(out_of_range::create(408,
						"excessive array size: " + std::to_string(len)));
				}

				return true;
			}

			bool end_array()
			{
				ref_stack.pop_back();
				return true;
			}

			bool parse_error(std::size_t /*unused*/, const std::string& /*unused*/,
				const detail::exception& ex)
			{
				errored = true;
				if (allow_exceptions)
				{
					// determine the proper exception type from the id
					switch ((ex.id / 100) % 100)
					{
					case 1:
						JSON_THROW(*static_cast<const detail::parse_error*>(&ex));
					case 4:
						JSON_THROW(*static_cast<const detail::out_of_range*>(&ex));
						// LCOV_EXCL_START
					case 2:
						JSON_THROW(*static_cast<const detail::invalid_iterator*>(&ex));
					case 3:
						JSON_THROW(*static_cast<const detail::type_error*>(&ex));
					case 5:
						JSON_THROW(*static_cast<const detail::other_error*>(&ex));
					default:
						assert(false);
						// LCOV_EXCL_STOP
					}
				}
				return false;
			}

			constexpr bool is_errored() const
			{
				return errored;
			}

		private:
			/*!
			@invariant If the ref stack is empty, then the passed value will be the new
					   root.
			@invariant If the ref stack contains a value, then it is an array or an
					   object to which we can add elements
			*/
			template<typename Value>
			JSON_HEDLEY_RETURNS_NON_NULL
				BasicJsonType* handle_value(Value&& v)
			{
				if (ref_stack.empty())
				{
					root = BasicJsonType(std::forward<Value>(v));
					return &root;
				}

				assert(ref_stack.back()->is_array() or ref_stack.back()->is_object());

				if (ref_stack.back()->is_array())
				{
					ref_stack.back()->m_value.array->emplace_back(std::forward<Value>(v));
					return &(ref_stack.back()->m_value.array->back());
				}

				assert(ref_stack.back()->is_object());
				assert(object_element);
				*object_element = BasicJsonType(std::forward<Value>(v));
				return object_element;
			}

			/// the parsed JSON value
			BasicJsonType& root;
			/// stack to model hierarchy of values
			std::vector<BasicJsonType*> ref_stack{};
			/// helper to hold the reference for the next object element
			BasicJsonType* object_element = nullptr;
			/// whether a syntax error occurred
			bool errored = false;
			/// whether to throw exceptions in case of errors
			const bool allow_exceptions = true;
		};

		template<typename BasicJsonType>
		class json_sax_dom_callback_parser
		{
		public:
			using number_integer_t = typename BasicJsonType::number_integer_t;
			using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
			using number_float_t = typename BasicJsonType::number_float_t;
			using string_t = typename BasicJsonType::string_t;
			using parser_callback_t = typename BasicJsonType::parser_callback_t;
			using parse_event_t = typename BasicJsonType::parse_event_t;

			json_sax_dom_callback_parser(BasicJsonType& r,
				const parser_callback_t cb,
				const bool allow_exceptions_ = true)
				: root(r), callback(cb), allow_exceptions(allow_exceptions_)
			{
				keep_stack.push_back(true);
			}

			// make class move-only
			json_sax_dom_callback_parser(const json_sax_dom_callback_parser&) = delete;
			json_sax_dom_callback_parser(json_sax_dom_callback_parser&&) = default;
			json_sax_dom_callback_parser& operator=(const json_sax_dom_callback_parser&) = delete;
			json_sax_dom_callback_parser& operator=(json_sax_dom_callback_parser&&) = default;
			~json_sax_dom_callback_parser() = default;

			bool null()
			{
				handle_value(nullptr);
				return true;
			}

			bool boolean(bool val)
			{
				handle_value(val);
				return true;
			}

			bool number_integer(number_integer_t val)
			{
				handle_value(val);
				return true;
			}

			bool number_unsigned(number_unsigned_t val)
			{
				handle_value(val);
				return true;
			}

			bool number_float(number_float_t val, const string_t& /*unused*/)
			{
				handle_value(val);
				return true;
			}

			bool string(string_t& val)
			{
				handle_value(val);
				return true;
			}

			bool start_object(std::size_t len)
			{
				// check callback for object start
				const bool keep = callback(static_cast<int>(ref_stack.size()), parse_event_t::object_start, discarded);
				keep_stack.push_back(keep);

				auto val = handle_value(BasicJsonType::value_t::object, true);
				ref_stack.push_back(val.second);

				// check object limit
				if (ref_stack.back() and JSON_HEDLEY_UNLIKELY(len != std::size_t(-1) and len > ref_stack.back()->max_size()))
				{
					JSON_THROW(out_of_range::create(408, "excessive object size: " + std::to_string(len)));
				}

				return true;
			}

			bool key(string_t& val)
			{
				BasicJsonType k = BasicJsonType(val);

				// check callback for key
				const bool keep = callback(static_cast<int>(ref_stack.size()), parse_event_t::key, k);
				key_keep_stack.push_back(keep);

				// add discarded value at given key and store the reference for later
				if (keep and ref_stack.back())
				{
					object_element = &(ref_stack.back()->m_value.object->operator[](val) = discarded);
				}

				return true;
			}

			bool end_object()
			{
				if (ref_stack.back() and not callback(static_cast<int>(ref_stack.size()) - 1, parse_event_t::object_end, *ref_stack.back()))
				{
					// discard object
					*ref_stack.back() = discarded;
				}

				assert(not ref_stack.empty());
				assert(not keep_stack.empty());
				ref_stack.pop_back();
				keep_stack.pop_back();

				if (not ref_stack.empty() and ref_stack.back() and ref_stack.back()->is_object())
				{
					// remove discarded value
					for (auto it = ref_stack.back()->begin(); it != ref_stack.back()->end(); ++it)
					{
						if (it->is_discarded())
						{
							ref_stack.back()->erase(it);
							break;
						}
					}
				}

				return true;
			}

			bool start_array(std::size_t len)
			{
				const bool keep = callback(static_cast<int>(ref_stack.size()), parse_event_t::array_start, discarded);
				keep_stack.push_back(keep);

				auto val = handle_value(BasicJsonType::value_t::array, true);
				ref_stack.push_back(val.second);

				// check array limit
				if (ref_stack.back() and JSON_HEDLEY_UNLIKELY(len != std::size_t(-1) and len > ref_stack.back()->max_size()))
				{
					JSON_THROW(out_of_range::create(408, "excessive array size: " + std::to_string(len)));
				}

				return true;
			}

			bool end_array()
			{
				bool keep = true;

				if (ref_stack.back())
				{
					keep = callback(static_cast<int>(ref_stack.size()) - 1, parse_event_t::array_end, *ref_stack.back());
					if (not keep)
					{
						// discard array
						*ref_stack.back() = discarded;
					}
				}

				assert(not ref_stack.empty());
				assert(not keep_stack.empty());
				ref_stack.pop_back();
				keep_stack.pop_back();

				// remove discarded value
				if (not keep and not ref_stack.empty() and ref_stack.back()->is_array())
				{
					ref_stack.back()->m_value.array->pop_back();
				}

				return true;
			}

			bool parse_error(std::size_t /*unused*/, const std::string& /*unused*/,
				const detail::exception& ex)
			{
				errored = true;
				if (allow_exceptions)
				{
					// determine the proper exception type from the id
					switch ((ex.id / 100) % 100)
					{
					case 1:
						JSON_THROW(*static_cast<const detail::parse_error*>(&ex));
					case 4:
						JSON_THROW(*static_cast<const detail::out_of_range*>(&ex));
						// LCOV_EXCL_START
					case 2:
						JSON_THROW(*static_cast<const detail::invalid_iterator*>(&ex));
					case 3:
						JSON_THROW(*static_cast<const detail::type_error*>(&ex));
					case 5:
						JSON_THROW(*static_cast<const detail::other_error*>(&ex));
					default:
						assert(false);
						// LCOV_EXCL_STOP
					}
				}
				return false;
			}

			constexpr bool is_errored() const
			{
				return errored;
			}

		private:
			/*!
			@param[in] v  value to add to the JSON value we build during parsing
			@param[in] skip_callback  whether we should skip calling the callback
					   function; this is required after start_array() and
					   start_object() SAX events, because otherwise we would call the
					   callback function with an empty array or object, respectively.
			@invariant If the ref stack is empty, then the passed value will be the new
					   root.
			@invariant If the ref stack contains a value, then it is an array or an
					   object to which we can add elements
			@return pair of boolean (whether value should be kept) and pointer (to the
					passed value in the ref_stack hierarchy; nullptr if not kept)
			*/
			template<typename Value>
			std::pair<bool, BasicJsonType*> handle_value(Value&& v, const bool skip_callback = false)
			{
				assert(not keep_stack.empty());

				// do not handle this value if we know it would be added to a discarded
				// container
				if (not keep_stack.back())
				{
					return { false, nullptr };
				}

				// create value
				auto value = BasicJsonType(std::forward<Value>(v));

				// check callback
				const bool keep = skip_callback or callback(static_cast<int>(ref_stack.size()), parse_event_t::value, value);

				// do not handle this value if we just learnt it shall be discarded
				if (not keep)
				{
					return { false, nullptr };
				}

				if (ref_stack.empty())
				{
					root = std::move(value);
					return { true, &root };
				}

				// skip this value if we already decided to skip the parent
				// (https://github.com/nlohmann/json/issues/971#issuecomment-413678360)
				if (not ref_stack.back())
				{
					return { false, nullptr };
				}

				// we now only expect arrays and objects
				assert(ref_stack.back()->is_array() or ref_stack.back()->is_object());

				// array
				if (ref_stack.back()->is_array())
				{
					ref_stack.back()->m_value.array->push_back(std::move(value));
					return { true, &(ref_stack.back()->m_value.array->back()) };
				}

				// object
				assert(ref_stack.back()->is_object());
				// check if we should store an element for the current key
				assert(not key_keep_stack.empty());
				const bool store_element = key_keep_stack.back();
				key_keep_stack.pop_back();

				if (not store_element)
				{
					return { false, nullptr };
				}

				assert(object_element);
				*object_element = std::move(value);
				return { true, object_element };
			}

			/// the parsed JSON value
			BasicJsonType& root;
			/// stack to model hierarchy of values
			std::vector<BasicJsonType*> ref_stack{};
			/// stack to manage which values to keep
			std::vector<bool> keep_stack{};
			/// stack to manage which object keys to keep
			std::vector<bool> key_keep_stack{};
			/// helper to hold the reference for the next object element
			BasicJsonType* object_element = nullptr;
			/// whether a syntax error occurred
			bool errored = false;
			/// callback function
			const parser_callback_t callback = nullptr;
			/// whether to throw exceptions in case of errors
			const bool allow_exceptions = true;
			/// a discarded value for the callback
			BasicJsonType discarded = BasicJsonType::value_t::discarded;
		};

		template<typename BasicJsonType>
		class json_sax_acceptor
		{
		public:
			using number_integer_t = typename BasicJsonType::number_integer_t;
			using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
			using number_float_t = typename BasicJsonType::number_float_t;
			using string_t = typename BasicJsonType::string_t;

			bool null()
			{
				return true;
			}

			bool boolean(bool /*unused*/)
			{
				return true;
			}

			bool number_integer(number_integer_t /*unused*/)
			{
				return true;
			}

			bool number_unsigned(number_unsigned_t /*unused*/)
			{
				return true;
			}

			bool number_float(number_float_t /*unused*/, const string_t& /*unused*/)
			{
				return true;
			}

			bool string(string_t& /*unused*/)
			{
				return true;
			}

			bool start_object(std::size_t  /*unused*/ = std::size_t(-1))
			{
				return true;
			}

			bool key(string_t& /*unused*/)
			{
				return true;
			}

			bool end_object()
			{
				return true;
			}

			bool start_array(std::size_t  /*unused*/ = std::size_t(-1))
			{
				return true;
			}

			bool end_array()
			{
				return true;
			}

			bool parse_error(std::size_t /*unused*/, const std::string& /*unused*/, const detail::exception& /*unused*/)
			{
				return false;
			}
		};
	}  // namespace detail

}  // namespace nlohmann

// #include <nlohmann/detail/macro_scope.hpp>

// #include <nlohmann/detail/meta/is_sax.hpp>


#include <cstdint> // size_t
#include <utility> // declval
#include <string> // string

// #include <nlohmann/detail/meta/detected.hpp>

// #include <nlohmann/detail/meta/type_traits.hpp>


namespace nlohmann
{
	namespace detail
	{
		template <typename T>
		using null_function_t = decltype(std::declval<T&>().null());

		template <typename T>
		using boolean_function_t =
			decltype(std::declval<T&>().boolean(std::declval<bool>()));

		template <typename T, typename Integer>
		using number_integer_function_t =
			decltype(std::declval<T&>().number_integer(std::declval<Integer>()));

		template <typename T, typename Unsigned>
		using number_unsigned_function_t =
			decltype(std::declval<T&>().number_unsigned(std::declval<Unsigned>()));

		template <typename T, typename Float, typename String>
		using number_float_function_t = decltype(std::declval<T&>().number_float(
			std::declval<Float>(), std::declval<const String&>()));

		template <typename T, typename String>
		using string_function_t =
			decltype(std::declval<T&>().string(std::declval<String&>()));

		template <typename T>
		using start_object_function_t =
			decltype(std::declval<T&>().start_object(std::declval<std::size_t>()));

		template <typename T, typename String>
		using key_function_t =
			decltype(std::declval<T&>().key(std::declval<String&>()));

		template <typename T>
		using end_object_function_t = decltype(std::declval<T&>().end_object());

		template <typename T>
		using start_array_function_t =
			decltype(std::declval<T&>().start_array(std::declval<std::size_t>()));

		template <typename T>
		using end_array_function_t = decltype(std::declval<T&>().end_array());

		template <typename T, typename Exception>
		using parse_error_function_t = decltype(std::declval<T&>().parse_error(
			std::declval<std::size_t>(), std::declval<const std::string&>(),
			std::declval<const Exception&>()));

		template <typename SAX, typename BasicJsonType>
		struct is_sax
		{
		private:
			static_assert(is_basic_json<BasicJsonType>::value,
				"BasicJsonType must be of type basic_json<...>");

			using number_integer_t = typename BasicJsonType::number_integer_t;
			using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
			using number_float_t = typename BasicJsonType::number_float_t;
			using string_t = typename BasicJsonType::string_t;
			using exception_t = typename BasicJsonType::exception;

		public:
			static constexpr bool value =
				is_detected_exact<bool, null_function_t, SAX>::value &&
				is_detected_exact<bool, boolean_function_t, SAX>::value &&
				is_detected_exact<bool, number_integer_function_t, SAX,
				number_integer_t>::value &&
				is_detected_exact<bool, number_unsigned_function_t, SAX,
				number_unsigned_t>::value &&
				is_detected_exact<bool, number_float_function_t, SAX, number_float_t,
				string_t>::value &&
				is_detected_exact<bool, string_function_t, SAX, string_t>::value &&
				is_detected_exact<bool, start_object_function_t, SAX>::value &&
				is_detected_exact<bool, key_function_t, SAX, string_t>::value &&
				is_detected_exact<bool, end_object_function_t, SAX>::value &&
				is_detected_exact<bool, start_array_function_t, SAX>::value &&
				is_detected_exact<bool, end_array_function_t, SAX>::value &&
				is_detected_exact<bool, parse_error_function_t, SAX, exception_t>::value;
		};

		template <typename SAX, typename BasicJsonType>
		struct is_sax_static_asserts
		{
		private:
			static_assert(is_basic_json<BasicJsonType>::value,
				"BasicJsonType must be of type basic_json<...>");

			using number_integer_t = typename BasicJsonType::number_integer_t;
			using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
			using number_float_t = typename BasicJsonType::number_float_t;
			using string_t = typename BasicJsonType::string_t;
			using exception_t = typename BasicJsonType::exception;

		public:
			static_assert(is_detected_exact<bool, null_function_t, SAX>::value,
				"Missing/invalid function: bool null()");
			static_assert(is_detected_exact<bool, boolean_function_t, SAX>::value,
				"Missing/invalid function: bool boolean(bool)");
			static_assert(is_detected_exact<bool, boolean_function_t, SAX>::value,
				"Missing/invalid function: bool boolean(bool)");
			static_assert(
				is_detected_exact<bool, number_integer_function_t, SAX,
				number_integer_t>::value,
				"Missing/invalid function: bool number_integer(number_integer_t)");
			static_assert(
				is_detected_exact<bool, number_unsigned_function_t, SAX,
				number_unsigned_t>::value,
				"Missing/invalid function: bool number_unsigned(number_unsigned_t)");
			static_assert(is_detected_exact<bool, number_float_function_t, SAX,
				number_float_t, string_t>::value,
				"Missing/invalid function: bool number_float(number_float_t, const string_t&)");
			static_assert(
				is_detected_exact<bool, string_function_t, SAX, string_t>::value,
				"Missing/invalid function: bool string(string_t&)");
			static_assert(is_detected_exact<bool, start_object_function_t, SAX>::value,
				"Missing/invalid function: bool start_object(std::size_t)");
			static_assert(is_detected_exact<bool, key_function_t, SAX, string_t>::value,
				"Missing/invalid function: bool key(string_t&)");
			static_assert(is_detected_exact<bool, end_object_function_t, SAX>::value,
				"Missing/invalid function: bool end_object()");
			static_assert(is_detected_exact<bool, start_array_function_t, SAX>::value,
				"Missing/invalid function: bool start_array(std::size_t)");
			static_assert(is_detected_exact<bool, end_array_function_t, SAX>::value,
				"Missing/invalid function: bool end_array()");
			static_assert(
				is_detected_exact<bool, parse_error_function_t, SAX, exception_t>::value,
				"Missing/invalid function: bool parse_error(std::size_t, const "
				"std::string&, const exception&)");
		};
	}  // namespace detail
}  // namespace nlohmann

// #include <nlohmann/detail/value_t.hpp>


namespace nlohmann
{
	namespace detail
	{
		///////////////////
		// binary reader //
		///////////////////

		/*!
		@brief deserialization of CBOR, MessagePack, and UBJSON values
		*/
		template<typename BasicJsonType, typename SAX = json_sax_dom_parser<BasicJsonType>>
		class binary_reader
		{
			using number_integer_t = typename BasicJsonType::number_integer_t;
			using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
			using number_float_t = typename BasicJsonType::number_float_t;
			using string_t = typename BasicJsonType::string_t;
			using json_sax_t = SAX;

		public:
			/*!
			@brief create a binary reader
			@param[in] adapter  input adapter to read from
			*/
			explicit binary_reader(input_adapter_t adapter) : ia(std::move(adapter))
			{
				(void)detail::is_sax_static_asserts<SAX, BasicJsonType> {};
				assert(ia);
			}

			// make class move-only
			binary_reader(const binary_reader&) = delete;
			binary_reader(binary_reader&&) = default;
			binary_reader& operator=(const binary_reader&) = delete;
			binary_reader& operator=(binary_reader&&) = default;
			~binary_reader() = default;

			/*!
			@param[in] format  the binary format to parse
			@param[in] sax_    a SAX event processor
			@param[in] strict  whether to expect the input to be consumed completed
			@return
			*/
			JSON_HEDLEY_NON_NULL(3)
				bool sax_parse(const input_format_t format,
					json_sax_t* sax_,
					const bool strict = true)
			{
				sax = sax_;
				bool result = false;

				switch (format)
				{
				case input_format_t::bson:
					result = parse_bson_internal();
					break;

				case input_format_t::cbor:
					result = parse_cbor_internal();
					break;

				case input_format_t::msgpack:
					result = parse_msgpack_internal();
					break;

				case input_format_t::ubjson:
					result = parse_ubjson_internal();
					break;

				default:            // LCOV_EXCL_LINE
					assert(false);  // LCOV_EXCL_LINE
				}

				// strict mode: next byte must be EOF
				if (result and strict)
				{
					if (format == input_format_t::ubjson)
					{
						get_ignore_noop();
					}
					else
					{
						get();
					}

					if (JSON_HEDLEY_UNLIKELY(current != std::char_traits<char>::eof()))
					{
						return sax->parse_error(chars_read, get_token_string(),
							parse_error::create(110, chars_read, exception_message(format, "expected end of input; last byte: 0x" + get_token_string(), "value")));
					}
				}

				return result;
			}

			/*!
			@brief determine system byte order
			@return true if and only if system's byte order is little endian
			@note from http://stackoverflow.com/a/1001328/266378
			*/
			static constexpr bool little_endianess(int num = 1) noexcept
			{
				return *reinterpret_cast<char*>(&num) == 1;
			}

		private:
			//////////
			// BSON //
			//////////

			/*!
			@brief Reads in a BSON-object and passes it to the SAX-parser.
			@return whether a valid BSON-value was passed to the SAX parser
			*/
			bool parse_bson_internal()
			{
				std::int32_t document_size;
				get_number<std::int32_t, true>(input_format_t::bson, document_size);

				if (JSON_HEDLEY_UNLIKELY(not sax->start_object(std::size_t(-1))))
				{
					return false;
				}

				if (JSON_HEDLEY_UNLIKELY(not parse_bson_element_list(/*is_array*/false)))
				{
					return false;
				}

				return sax->end_object();
			}

			/*!
			@brief Parses a C-style string from the BSON input.
			@param[in, out] result  A reference to the string variable where the read
									string is to be stored.
			@return `true` if the \x00-byte indicating the end of the string was
					 encountered before the EOF; false` indicates an unexpected EOF.
			*/
			bool get_bson_cstr(string_t& result)
			{
				auto out = std::back_inserter(result);
				while (true)
				{
					get();
					if (JSON_HEDLEY_UNLIKELY(not unexpect_eof(input_format_t::bson, "cstring")))
					{
						return false;
					}
					if (current == 0x00)
					{
						return true;
					}
					*out++ = static_cast<char>(current);
				}

				return true;
			}

			/*!
			@brief Parses a zero-terminated string of length @a len from the BSON
				   input.
			@param[in] len  The length (including the zero-byte at the end) of the
							string to be read.
			@param[in, out] result  A reference to the string variable where the read
									string is to be stored.
			@tparam NumberType The type of the length @a len
			@pre len >= 1
			@return `true` if the string was successfully parsed
			*/
			template<typename NumberType>
			bool get_bson_string(const NumberType len, string_t& result)
			{
				if (JSON_HEDLEY_UNLIKELY(len < 1))
				{
					auto last_token = get_token_string();
					return sax->parse_error(chars_read, last_token, parse_error::create(112, chars_read, exception_message(input_format_t::bson, "string length must be at least 1, is " + std::to_string(len), "string")));
				}

				return get_string(input_format_t::bson, len - static_cast<NumberType>(1), result) and get() != std::char_traits<char>::eof();
			}

			/*!
			@brief Read a BSON document element of the given @a element_type.
			@param[in] element_type The BSON element type, c.f. http://bsonspec.org/spec.html
			@param[in] element_type_parse_position The position in the input stream,
					   where the `element_type` was read.
			@warning Not all BSON element types are supported yet. An unsupported
					 @a element_type will give rise to a parse_error.114:
					 Unsupported BSON record type 0x...
			@return whether a valid BSON-object/array was passed to the SAX parser
			*/
			bool parse_bson_element_internal(const int element_type,
				const std::size_t element_type_parse_position)
			{
				switch (element_type)
				{
				case 0x01: // double
				{
					double number;
					return get_number<double, true>(input_format_t::bson, number) and sax->number_float(static_cast<number_float_t>(number), "");
				}

				case 0x02: // string
				{
					std::int32_t len;
					string_t value;
					return get_number<std::int32_t, true>(input_format_t::bson, len) and get_bson_string(len, value) and sax->string(value);
				}

				case 0x03: // object
				{
					return parse_bson_internal();
				}

				case 0x04: // array
				{
					return parse_bson_array();
				}

				case 0x08: // boolean
				{
					return sax->boolean(get() != 0);
				}

				case 0x0A: // null
				{
					return sax->null();
				}

				case 0x10: // int32
				{
					std::int32_t value;
					return get_number<std::int32_t, true>(input_format_t::bson, value) and sax->number_integer(value);
				}

				case 0x12: // int64
				{
					std::int64_t value;
					return get_number<std::int64_t, true>(input_format_t::bson, value) and sax->number_integer(value);
				}

				default: // anything else not supported (yet)
				{
					std::array<char, 3> cr{ {} };
					(std::snprintf)(cr.data(), cr.size(), "%.2hhX", static_cast<unsigned char>(element_type));
					return sax->parse_error(element_type_parse_position, std::string(cr.data()), parse_error::create(114, element_type_parse_position, "Unsupported BSON record type 0x" + std::string(cr.data())));
				}
				}
			}

			/*!
			@brief Read a BSON element list (as specified in the BSON-spec)
			The same binary layout is used for objects and arrays, hence it must be
			indicated with the argument @a is_array which one is expected
			(true --> array, false --> object).
			@param[in] is_array Determines if the element list being read is to be
								treated as an object (@a is_array == false), or as an
								array (@a is_array == true).
			@return whether a valid BSON-object/array was passed to the SAX parser
			*/
			bool parse_bson_element_list(const bool is_array)
			{
				string_t key;
				while (int element_type = get())
				{
					if (JSON_HEDLEY_UNLIKELY(not unexpect_eof(input_format_t::bson, "element list")))
					{
						return false;
					}

					const std::size_t element_type_parse_position = chars_read;
					if (JSON_HEDLEY_UNLIKELY(not get_bson_cstr(key)))
					{
						return false;
					}

					if (not is_array and not sax->key(key))
					{
						return false;
					}

					if (JSON_HEDLEY_UNLIKELY(not parse_bson_element_internal(element_type, element_type_parse_position)))
					{
						return false;
					}

					// get_bson_cstr only appends
					key.clear();
				}

				return true;
			}

			/*!
			@brief Reads an array from the BSON input and passes it to the SAX-parser.
			@return whether a valid BSON-array was passed to the SAX parser
			*/
			bool parse_bson_array()
			{
				std::int32_t document_size;
				get_number<std::int32_t, true>(input_format_t::bson, document_size);

				if (JSON_HEDLEY_UNLIKELY(not sax->start_array(std::size_t(-1))))
				{
					return false;
				}

				if (JSON_HEDLEY_UNLIKELY(not parse_bson_element_list(/*is_array*/true)))
				{
					return false;
				}

				return sax->end_array();
			}

			//////////
			// CBOR //
			//////////

			/*!
			@param[in] get_char  whether a new character should be retrieved from the
								 input (true, default) or whether the last read
								 character should be considered instead
			@return whether a valid CBOR value was passed to the SAX parser
			*/
			bool parse_cbor_internal(const bool get_char = true)
			{
				switch (get_char ? get() : current)
				{
					// EOF
				case std::char_traits<char>::eof():
					return unexpect_eof(input_format_t::cbor, "value");

					// Integer 0x00..0x17 (0..23)
				case 0x00:
				case 0x01:
				case 0x02:
				case 0x03:
				case 0x04:
				case 0x05:
				case 0x06:
				case 0x07:
				case 0x08:
				case 0x09:
				case 0x0A:
				case 0x0B:
				case 0x0C:
				case 0x0D:
				case 0x0E:
				case 0x0F:
				case 0x10:
				case 0x11:
				case 0x12:
				case 0x13:
				case 0x14:
				case 0x15:
				case 0x16:
				case 0x17:
					return sax->number_unsigned(static_cast<number_unsigned_t>(current));

				case 0x18: // Unsigned integer (one-byte uint8_t follows)
				{
					std::uint8_t number;
					return get_number(input_format_t::cbor, number) and sax->number_unsigned(number);
				}

				case 0x19: // Unsigned integer (two-byte uint16_t follows)
				{
					std::uint16_t number;
					return get_number(input_format_t::cbor, number) and sax->number_unsigned(number);
				}

				case 0x1A: // Unsigned integer (four-byte uint32_t follows)
				{
					std::uint32_t number;
					return get_number(input_format_t::cbor, number) and sax->number_unsigned(number);
				}

				case 0x1B: // Unsigned integer (eight-byte uint64_t follows)
				{
					std::uint64_t number;
					return get_number(input_format_t::cbor, number) and sax->number_unsigned(number);
				}

				// Negative integer -1-0x00..-1-0x17 (-1..-24)
				case 0x20:
				case 0x21:
				case 0x22:
				case 0x23:
				case 0x24:
				case 0x25:
				case 0x26:
				case 0x27:
				case 0x28:
				case 0x29:
				case 0x2A:
				case 0x2B:
				case 0x2C:
				case 0x2D:
				case 0x2E:
				case 0x2F:
				case 0x30:
				case 0x31:
				case 0x32:
				case 0x33:
				case 0x34:
				case 0x35:
				case 0x36:
				case 0x37:
					return sax->number_integer(static_cast<std::int8_t>(0x20 - 1 - current));

				case 0x38: // Negative integer (one-byte uint8_t follows)
				{
					std::uint8_t number;
					return get_number(input_format_t::cbor, number) and sax->number_integer(static_cast<number_integer_t>(-1) - number);
				}

				case 0x39: // Negative integer -1-n (two-byte uint16_t follows)
				{
					std::uint16_t number;
					return get_number(input_format_t::cbor, number) and sax->number_integer(static_cast<number_integer_t>(-1) - number);
				}

				case 0x3A: // Negative integer -1-n (four-byte uint32_t follows)
				{
					std::uint32_t number;
					return get_number(input_format_t::cbor, number) and sax->number_integer(static_cast<number_integer_t>(-1) - number);
				}

				case 0x3B: // Negative integer -1-n (eight-byte uint64_t follows)
				{
					std::uint64_t number;
					return get_number(input_format_t::cbor, number) and sax->number_integer(static_cast<number_integer_t>(-1)
						- static_cast<number_integer_t>(number));
				}

				// UTF-8 string (0x00..0x17 bytes follow)
				case 0x60:
				case 0x61:
				case 0x62:
				case 0x63:
				case 0x64:
				case 0x65:
				case 0x66:
				case 0x67:
				case 0x68:
				case 0x69:
				case 0x6A:
				case 0x6B:
				case 0x6C:
				case 0x6D:
				case 0x6E:
				case 0x6F:
				case 0x70:
				case 0x71:
				case 0x72:
				case 0x73:
				case 0x74:
				case 0x75:
				case 0x76:
				case 0x77:
				case 0x78: // UTF-8 string (one-byte uint8_t for n follows)
				case 0x79: // UTF-8 string (two-byte uint16_t for n follow)
				case 0x7A: // UTF-8 string (four-byte uint32_t for n follow)
				case 0x7B: // UTF-8 string (eight-byte uint64_t for n follow)
				case 0x7F: // UTF-8 string (indefinite length)
				{
					string_t s;
					return get_cbor_string(s) and sax->string(s);
				}

				// array (0x00..0x17 data items follow)
				case 0x80:
				case 0x81:
				case 0x82:
				case 0x83:
				case 0x84:
				case 0x85:
				case 0x86:
				case 0x87:
				case 0x88:
				case 0x89:
				case 0x8A:
				case 0x8B:
				case 0x8C:
				case 0x8D:
				case 0x8E:
				case 0x8F:
				case 0x90:
				case 0x91:
				case 0x92:
				case 0x93:
				case 0x94:
				case 0x95:
				case 0x96:
				case 0x97:
					return get_cbor_array(static_cast<std::size_t>(static_cast<unsigned int>(current) & 0x1Fu));

				case 0x98: // array (one-byte uint8_t for n follows)
				{
					std::uint8_t len;
					return get_number(input_format_t::cbor, len) and get_cbor_array(static_cast<std::size_t>(len));
				}

				case 0x99: // array (two-byte uint16_t for n follow)
				{
					std::uint16_t len;
					return get_number(input_format_t::cbor, len) and get_cbor_array(static_cast<std::size_t>(len));
				}

				case 0x9A: // array (four-byte uint32_t for n follow)
				{
					std::uint32_t len;
					return get_number(input_format_t::cbor, len) and get_cbor_array(static_cast<std::size_t>(len));
				}

				case 0x9B: // array (eight-byte uint64_t for n follow)
				{
					std::uint64_t len;
					return get_number(input_format_t::cbor, len) and get_cbor_array(static_cast<std::size_t>(len));
				}

				case 0x9F: // array (indefinite length)
					return get_cbor_array(std::size_t(-1));

					// map (0x00..0x17 pairs of data items follow)
				case 0xA0:
				case 0xA1:
				case 0xA2:
				case 0xA3:
				case 0xA4:
				case 0xA5:
				case 0xA6:
				case 0xA7:
				case 0xA8:
				case 0xA9:
				case 0xAA:
				case 0xAB:
				case 0xAC:
				case 0xAD:
				case 0xAE:
				case 0xAF:
				case 0xB0:
				case 0xB1:
				case 0xB2:
				case 0xB3:
				case 0xB4:
				case 0xB5:
				case 0xB6:
				case 0xB7:
					return get_cbor_object(static_cast<std::size_t>(static_cast<unsigned int>(current) & 0x1Fu));

				case 0xB8: // map (one-byte uint8_t for n follows)
				{
					std::uint8_t len;
					return get_number(input_format_t::cbor, len) and get_cbor_object(static_cast<std::size_t>(len));
				}

				case 0xB9: // map (two-byte uint16_t for n follow)
				{
					std::uint16_t len;
					return get_number(input_format_t::cbor, len) and get_cbor_object(static_cast<std::size_t>(len));
				}

				case 0xBA: // map (four-byte uint32_t for n follow)
				{
					std::uint32_t len;
					return get_number(input_format_t::cbor, len) and get_cbor_object(static_cast<std::size_t>(len));
				}

				case 0xBB: // map (eight-byte uint64_t for n follow)
				{
					std::uint64_t len;
					return get_number(input_format_t::cbor, len) and get_cbor_object(static_cast<std::size_t>(len));
				}

				case 0xBF: // map (indefinite length)
					return get_cbor_object(std::size_t(-1));

				case 0xF4: // false
					return sax->boolean(false);

				case 0xF5: // true
					return sax->boolean(true);

				case 0xF6: // null
					return sax->null();

				case 0xF9: // Half-Precision Float (two-byte IEEE 754)
				{
					const int byte1_raw = get();
					if (JSON_HEDLEY_UNLIKELY(not unexpect_eof(input_format_t::cbor, "number")))
					{
						return false;
					}
					const int byte2_raw = get();
					if (JSON_HEDLEY_UNLIKELY(not unexpect_eof(input_format_t::cbor, "number")))
					{
						return false;
					}

					const auto byte1 = static_cast<unsigned char>(byte1_raw);
					const auto byte2 = static_cast<unsigned char>(byte2_raw);

					// code from RFC 7049, Appendix D, Figure 3:
					// As half-precision floating-point numbers were only added
					// to IEEE 754 in 2008, today's programming platforms often
					// still only have limited support for them. It is very
					// easy to include at least decoding support for them even
					// without such support. An example of a small decoder for
					// half-precision floating-point numbers in the C language
					// is shown in Fig. 3.
					const auto half = static_cast<unsigned int>((byte1 << 8u) + byte2);
					const double val = [&half]
					{
						const int exp = (half >> 10u) & 0x1Fu;
						const unsigned int mant = half & 0x3FFu;
						assert(0 <= exp and exp <= 32);
						assert(mant <= 1024);
						switch (exp)
						{
						case 0:
							return std::ldexp(mant, -24);
						case 31:
							return (mant == 0)
								? std::numeric_limits<double>::infinity()
								: std::numeric_limits<double>::quiet_NaN();
						default:
							return std::ldexp(mant + 1024, exp - 25);
						}
					}();
					return sax->number_float((half & 0x8000u) != 0
						? static_cast<number_float_t>(-val)
						: static_cast<number_float_t>(val), "");
				}

				case 0xFA: // Single-Precision Float (four-byte IEEE 754)
				{
					float number;
					return get_number(input_format_t::cbor, number) and sax->number_float(static_cast<number_float_t>(number), "");
				}

				case 0xFB: // Double-Precision Float (eight-byte IEEE 754)
				{
					double number;
					return get_number(input_format_t::cbor, number) and sax->number_float(static_cast<number_float_t>(number), "");
				}

				default: // anything else (0xFF is handled inside the other types)
				{
					auto last_token = get_token_string();
					return sax->parse_error(chars_read, last_token, parse_error::create(112, chars_read, exception_message(input_format_t::cbor, "invalid byte: 0x" + last_token, "value")));
				}
				}
			}

			/*!
			@brief reads a CBOR string
			This function first reads starting bytes to determine the expected
			string length and then copies this number of bytes into a string.
			Additionally, CBOR's strings with indefinite lengths are supported.
			@param[out] result  created string
			@return whether string creation completed
			*/
			bool get_cbor_string(string_t& result)
			{
				if (JSON_HEDLEY_UNLIKELY(not unexpect_eof(input_format_t::cbor, "string")))
				{
					return false;
				}

				switch (current)
				{
					// UTF-8 string (0x00..0x17 bytes follow)
				case 0x60:
				case 0x61:
				case 0x62:
				case 0x63:
				case 0x64:
				case 0x65:
				case 0x66:
				case 0x67:
				case 0x68:
				case 0x69:
				case 0x6A:
				case 0x6B:
				case 0x6C:
				case 0x6D:
				case 0x6E:
				case 0x6F:
				case 0x70:
				case 0x71:
				case 0x72:
				case 0x73:
				case 0x74:
				case 0x75:
				case 0x76:
				case 0x77:
				{
					return get_string(input_format_t::cbor, static_cast<unsigned int>(current) & 0x1Fu, result);
				}

				case 0x78: // UTF-8 string (one-byte uint8_t for n follows)
				{
					std::uint8_t len;
					return get_number(input_format_t::cbor, len) and get_string(input_format_t::cbor, len, result);
				}

				case 0x79: // UTF-8 string (two-byte uint16_t for n follow)
				{
					std::uint16_t len;
					return get_number(input_format_t::cbor, len) and get_string(input_format_t::cbor, len, result);
				}

				case 0x7A: // UTF-8 string (four-byte uint32_t for n follow)
				{
					std::uint32_t len;
					return get_number(input_format_t::cbor, len) and get_string(input_format_t::cbor, len, result);
				}

				case 0x7B: // UTF-8 string (eight-byte uint64_t for n follow)
				{
					std::uint64_t len;
					return get_number(input_format_t::cbor, len) and get_string(input_format_t::cbor, len, result);
				}

				case 0x7F: // UTF-8 string (indefinite length)
				{
					while (get() != 0xFF)
					{
						string_t chunk;
						if (not get_cbor_string(chunk))
						{
							return false;
						}
						result.append(chunk);
					}
					return true;
				}

				default:
				{
					auto last_token = get_token_string();
					return sax->parse_error(chars_read, last_token, parse_error::create(113, chars_read, exception_message(input_format_t::cbor, "expected length specification (0x60-0x7B) or indefinite string type (0x7F); last byte: 0x" + last_token, "string")));
				}
				}
			}

			/*!
			@param[in] len  the length of the array or std::size_t(-1) for an
							array of indefinite size
			@return whether array creation completed
			*/
			bool get_cbor_array(const std::size_t len)
			{
				if (JSON_HEDLEY_UNLIKELY(not sax->start_array(len)))
				{
					return false;
				}

				if (len != std::size_t(-1))
				{
					for (std::size_t i = 0; i < len; ++i)
					{
						if (JSON_HEDLEY_UNLIKELY(not parse_cbor_internal()))
						{
							return false;
						}
					}
				}
				else
				{
					while (get() != 0xFF)
					{
						if (JSON_HEDLEY_UNLIKELY(not parse_cbor_internal(false)))
						{
							return false;
						}
					}
				}

				return sax->end_array();
			}

			/*!
			@param[in] len  the length of the object or std::size_t(-1) for an
							object of indefinite size
			@return whether object creation completed
			*/
			bool get_cbor_object(const std::size_t len)
			{
				if (JSON_HEDLEY_UNLIKELY(not sax->start_object(len)))
				{
					return false;
				}

				string_t key;
				if (len != std::size_t(-1))
				{
					for (std::size_t i = 0; i < len; ++i)
					{
						get();
						if (JSON_HEDLEY_UNLIKELY(not get_cbor_string(key) or not sax->key(key)))
						{
							return false;
						}

						if (JSON_HEDLEY_UNLIKELY(not parse_cbor_internal()))
						{
							return false;
						}
						key.clear();
					}
				}
				else
				{
					while (get() != 0xFF)
					{
						if (JSON_HEDLEY_UNLIKELY(not get_cbor_string(key) or not sax->key(key)))
						{
							return false;
						}

						if (JSON_HEDLEY_UNLIKELY(not parse_cbor_internal()))
						{
							return false;
						}
						key.clear();
					}
				}

				return sax->end_object();
			}

			/////////////
			// MsgPack //
			/////////////

			/*!
			@return whether a valid MessagePack value was passed to the SAX parser
			*/
			bool parse_msgpack_internal()
			{
				switch (get())
				{
					// EOF
				case std::char_traits<char>::eof():
					return unexpect_eof(input_format_t::msgpack, "value");

					// positive fixint
				case 0x00:
				case 0x01:
				case 0x02:
				case 0x03:
				case 0x04:
				case 0x05:
				case 0x06:
				case 0x07:
				case 0x08:
				case 0x09:
				case 0x0A:
				case 0x0B:
				case 0x0C:
				case 0x0D:
				case 0x0E:
				case 0x0F:
				case 0x10:
				case 0x11:
				case 0x12:
				case 0x13:
				case 0x14:
				case 0x15:
				case 0x16:
				case 0x17:
				case 0x18:
				case 0x19:
				case 0x1A:
				case 0x1B:
				case 0x1C:
				case 0x1D:
				case 0x1E:
				case 0x1F:
				case 0x20:
				case 0x21:
				case 0x22:
				case 0x23:
				case 0x24:
				case 0x25:
				case 0x26:
				case 0x27:
				case 0x28:
				case 0x29:
				case 0x2A:
				case 0x2B:
				case 0x2C:
				case 0x2D:
				case 0x2E:
				case 0x2F:
				case 0x30:
				case 0x31:
				case 0x32:
				case 0x33:
				case 0x34:
				case 0x35:
				case 0x36:
				case 0x37:
				case 0x38:
				case 0x39:
				case 0x3A:
				case 0x3B:
				case 0x3C:
				case 0x3D:
				case 0x3E:
				case 0x3F:
				case 0x40:
				case 0x41:
				case 0x42:
				case 0x43:
				case 0x44:
				case 0x45:
				case 0x46:
				case 0x47:
				case 0x48:
				case 0x49:
				case 0x4A:
				case 0x4B:
				case 0x4C:
				case 0x4D:
				case 0x4E:
				case 0x4F:
				case 0x50:
				case 0x51:
				case 0x52:
				case 0x53:
				case 0x54:
				case 0x55:
				case 0x56:
				case 0x57:
				case 0x58:
				case 0x59:
				case 0x5A:
				case 0x5B:
				case 0x5C:
				case 0x5D:
				case 0x5E:
				case 0x5F:
				case 0x60:
				case 0x61:
				case 0x62:
				case 0x63:
				case 0x64:
				case 0x65:
				case 0x66:
				case 0x67:
				case 0x68:
				case 0x69:
				case 0x6A:
				case 0x6B:
				case 0x6C:
				case 0x6D:
				case 0x6E:
				case 0x6F:
				case 0x70:
				case 0x71:
				case 0x72:
				case 0x73:
				case 0x74:
				case 0x75:
				case 0x76:
				case 0x77:
				case 0x78:
				case 0x79:
				case 0x7A:
				case 0x7B:
				case 0x7C:
				case 0x7D:
				case 0x7E:
				case 0x7F:
					return sax->number_unsigned(static_cast<number_unsigned_t>(current));

					// fixmap
				case 0x80:
				case 0x81:
				case 0x82:
				case 0x83:
				case 0x84:
				case 0x85:
				case 0x86:
				case 0x87:
				case 0x88:
				case 0x89:
				case 0x8A:
				case 0x8B:
				case 0x8C:
				case 0x8D:
				case 0x8E:
				case 0x8F:
					return get_msgpack_object(static_cast<std::size_t>(static_cast<unsigned int>(current) & 0x0Fu));

					// fixarray
				case 0x90:
				case 0x91:
				case 0x92:
				case 0x93:
				case 0x94:
				case 0x95:
				case 0x96:
				case 0x97:
				case 0x98:
				case 0x99:
				case 0x9A:
				case 0x9B:
				case 0x9C:
				case 0x9D:
				case 0x9E:
				case 0x9F:
					return get_msgpack_array(static_cast<std::size_t>(static_cast<unsigned int>(current) & 0x0Fu));

					// fixstr
				case 0xA0:
				case 0xA1:
				case 0xA2:
				case 0xA3:
				case 0xA4:
				case 0xA5:
				case 0xA6:
				case 0xA7:
				case 0xA8:
				case 0xA9:
				case 0xAA:
				case 0xAB:
				case 0xAC:
				case 0xAD:
				case 0xAE:
				case 0xAF:
				case 0xB0:
				case 0xB1:
				case 0xB2:
				case 0xB3:
				case 0xB4:
				case 0xB5:
				case 0xB6:
				case 0xB7:
				case 0xB8:
				case 0xB9:
				case 0xBA:
				case 0xBB:
				case 0xBC:
				case 0xBD:
				case 0xBE:
				case 0xBF:
				case 0xD9: // str 8
				case 0xDA: // str 16
				case 0xDB: // str 32
				{
					string_t s;
					return get_msgpack_string(s) and sax->string(s);
				}

				case 0xC0: // nil
					return sax->null();

				case 0xC2: // false
					return sax->boolean(false);

				case 0xC3: // true
					return sax->boolean(true);

				case 0xCA: // float 32
				{
					float number;
					return get_number(input_format_t::msgpack, number) and sax->number_float(static_cast<number_float_t>(number), "");
				}

				case 0xCB: // float 64
				{
					double number;
					return get_number(input_format_t::msgpack, number) and sax->number_float(static_cast<number_float_t>(number), "");
				}

				case 0xCC: // uint 8
				{
					std::uint8_t number;
					return get_number(input_format_t::msgpack, number) and sax->number_unsigned(number);
				}

				case 0xCD: // uint 16
				{
					std::uint16_t number;
					return get_number(input_format_t::msgpack, number) and sax->number_unsigned(number);
				}

				case 0xCE: // uint 32
				{
					std::uint32_t number;
					return get_number(input_format_t::msgpack, number) and sax->number_unsigned(number);
				}

				case 0xCF: // uint 64
				{
					std::uint64_t number;
					return get_number(input_format_t::msgpack, number) and sax->number_unsigned(number);
				}

				case 0xD0: // int 8
				{
					std::int8_t number;
					return get_number(input_format_t::msgpack, number) and sax->number_integer(number);
				}

				case 0xD1: // int 16
				{
					std::int16_t number;
					return get_number(input_format_t::msgpack, number) and sax->number_integer(number);
				}

				case 0xD2: // int 32
				{
					std::int32_t number;
					return get_number(input_format_t::msgpack, number) and sax->number_integer(number);
				}

				case 0xD3: // int 64
				{
					std::int64_t number;
					return get_number(input_format_t::msgpack, number) and sax->number_integer(number);
				}

				case 0xDC: // array 16
				{
					std::uint16_t len;
					return get_number(input_format_t::msgpack, len) and get_msgpack_array(static_cast<std::size_t>(len));
				}

				case 0xDD: // array 32
				{
					std::uint32_t len;
					return get_number(input_format_t::msgpack, len) and get_msgpack_array(static_cast<std::size_t>(len));
				}

				case 0xDE: // map 16
				{
					std::uint16_t len;
					return get_number(input_format_t::msgpack, len) and get_msgpack_object(static_cast<std::size_t>(len));
				}

				case 0xDF: // map 32
				{
					std::uint32_t len;
					return get_number(input_format_t::msgpack, len) and get_msgpack_object(static_cast<std::size_t>(len));
				}

				// negative fixint
				case 0xE0:
				case 0xE1:
				case 0xE2:
				case 0xE3:
				case 0xE4:
				case 0xE5:
				case 0xE6:
				case 0xE7:
				case 0xE8:
				case 0xE9:
				case 0xEA:
				case 0xEB:
				case 0xEC:
				case 0xED:
				case 0xEE:
				case 0xEF:
				case 0xF0:
				case 0xF1:
				case 0xF2:
				case 0xF3:
				case 0xF4:
				case 0xF5:
				case 0xF6:
				case 0xF7:
				case 0xF8:
				case 0xF9:
				case 0xFA:
				case 0xFB:
				case 0xFC:
				case 0xFD:
				case 0xFE:
				case 0xFF:
					return sax->number_integer(static_cast<std::int8_t>(current));

				default: // anything else
				{
					auto last_token = get_token_string();
					return sax->parse_error(chars_read, last_token, parse_error::create(112, chars_read, exception_message(input_format_t::msgpack, "invalid byte: 0x" + last_token, "value")));
				}
				}
			}

			/*!
			@brief reads a MessagePack string
			This function first reads starting bytes to determine the expected
			string length and then copies this number of bytes into a string.
			@param[out] result  created string
			@return whether string creation completed
			*/
			bool get_msgpack_string(string_t& result)
			{
				if (JSON_HEDLEY_UNLIKELY(not unexpect_eof(input_format_t::msgpack, "string")))
				{
					return false;
				}

				switch (current)
				{
					// fixstr
				case 0xA0:
				case 0xA1:
				case 0xA2:
				case 0xA3:
				case 0xA4:
				case 0xA5:
				case 0xA6:
				case 0xA7:
				case 0xA8:
				case 0xA9:
				case 0xAA:
				case 0xAB:
				case 0xAC:
				case 0xAD:
				case 0xAE:
				case 0xAF:
				case 0xB0:
				case 0xB1:
				case 0xB2:
				case 0xB3:
				case 0xB4:
				case 0xB5:
				case 0xB6:
				case 0xB7:
				case 0xB8:
				case 0xB9:
				case 0xBA:
				case 0xBB:
				case 0xBC:
				case 0xBD:
				case 0xBE:
				case 0xBF:
				{
					return get_string(input_format_t::msgpack, static_cast<unsigned int>(current) & 0x1Fu, result);
				}

				case 0xD9: // str 8
				{
					std::uint8_t len;
					return get_number(input_format_t::msgpack, len) and get_string(input_format_t::msgpack, len, result);
				}

				case 0xDA: // str 16
				{
					std::uint16_t len;
					return get_number(input_format_t::msgpack, len) and get_string(input_format_t::msgpack, len, result);
				}

				case 0xDB: // str 32
				{
					std::uint32_t len;
					return get_number(input_format_t::msgpack, len) and get_string(input_format_t::msgpack, len, result);
				}

				default:
				{
					auto last_token = get_token_string();
					return sax->parse_error(chars_read, last_token, parse_error::create(113, chars_read, exception_message(input_format_t::msgpack, "expected length specification (0xA0-0xBF, 0xD9-0xDB); last byte: 0x" + last_token, "string")));
				}
				}
			}

			/*!
			@param[in] len  the length of the array
			@return whether array creation completed
			*/
			bool get_msgpack_array(const std::size_t len)
			{
				if (JSON_HEDLEY_UNLIKELY(not sax->start_array(len)))
				{
					return false;
				}

				for (std::size_t i = 0; i < len; ++i)
				{
					if (JSON_HEDLEY_UNLIKELY(not parse_msgpack_internal()))
					{
						return false;
					}
				}

				return sax->end_array();
			}

			/*!
			@param[in] len  the length of the object
			@return whether object creation completed
			*/
			bool get_msgpack_object(const std::size_t len)
			{
				if (JSON_HEDLEY_UNLIKELY(not sax->start_object(len)))
				{
					return false;
				}

				string_t key;
				for (std::size_t i = 0; i < len; ++i)
				{
					get();
					if (JSON_HEDLEY_UNLIKELY(not get_msgpack_string(key) or not sax->key(key)))
					{
						return false;
					}

					if (JSON_HEDLEY_UNLIKELY(not parse_msgpack_internal()))
					{
						return false;
					}
					key.clear();
				}

				return sax->end_object();
			}

			////////////
			// UBJSON //
			////////////

			/*!
			@param[in] get_char  whether a new character should be retrieved from the
								 input (true, default) or whether the last read
								 character should be considered instead
			@return whether a valid UBJSON value was passed to the SAX parser
			*/
			bool parse_ubjson_internal(const bool get_char = true)
			{
				return get_ubjson_value(get_char ? get_ignore_noop() : current);
			}

			/*!
			@brief reads a UBJSON string
			This function is either called after reading the 'S' byte explicitly
			indicating a string, or in case of an object key where the 'S' byte can be
			left out.
			@param[out] result   created string
			@param[in] get_char  whether a new character should be retrieved from the
								 input (true, default) or whether the last read
								 character should be considered instead
			@return whether string creation completed
			*/
			bool get_ubjson_string(string_t& result, const bool get_char = true)
			{
				if (get_char)
				{
					get();  // TODO(niels): may we ignore N here?
				}

				if (JSON_HEDLEY_UNLIKELY(not unexpect_eof(input_format_t::ubjson, "value")))
				{
					return false;
				}

				switch (current)
				{
				case 'U':
				{
					std::uint8_t len;
					return get_number(input_format_t::ubjson, len) and get_string(input_format_t::ubjson, len, result);
				}

				case 'i':
				{
					std::int8_t len;
					return get_number(input_format_t::ubjson, len) and get_string(input_format_t::ubjson, len, result);
				}

				case 'I':
				{
					std::int16_t len;
					return get_number(input_format_t::ubjson, len) and get_string(input_format_t::ubjson, len, result);
				}

				case 'l':
				{
					std::int32_t len;
					return get_number(input_format_t::ubjson, len) and get_string(input_format_t::ubjson, len, result);
				}

				case 'L':
				{
					std::int64_t len;
					return get_number(input_format_t::ubjson, len) and get_string(input_format_t::ubjson, len, result);
				}

				default:
					auto last_token = get_token_string();
					return sax->parse_error(chars_read, last_token, parse_error::create(113, chars_read, exception_message(input_format_t::ubjson, "expected length type specification (U, i, I, l, L); last byte: 0x" + last_token, "string")));
				}
			}

			/*!
			@param[out] result  determined size
			@return whether size determination completed
			*/
			bool get_ubjson_size_value(std::size_t& result)
			{
				switch (get_ignore_noop())
				{
				case 'U':
				{
					std::uint8_t number;
					if (JSON_HEDLEY_UNLIKELY(not get_number(input_format_t::ubjson, number)))
					{
						return false;
					}
					result = static_cast<std::size_t>(number);
					return true;
				}

				case 'i':
				{
					std::int8_t number;
					if (JSON_HEDLEY_UNLIKELY(not get_number(input_format_t::ubjson, number)))
					{
						return false;
					}
					result = static_cast<std::size_t>(number);
					return true;
				}

				case 'I':
				{
					std::int16_t number;
					if (JSON_HEDLEY_UNLIKELY(not get_number(input_format_t::ubjson, number)))
					{
						return false;
					}
					result = static_cast<std::size_t>(number);
					return true;
				}

				case 'l':
				{
					std::int32_t number;
					if (JSON_HEDLEY_UNLIKELY(not get_number(input_format_t::ubjson, number)))
					{
						return false;
					}
					result = static_cast<std::size_t>(number);
					return true;
				}

				case 'L':
				{
					std::int64_t number;
					if (JSON_HEDLEY_UNLIKELY(not get_number(input_format_t::ubjson, number)))
					{
						return false;
					}
					result = static_cast<std::size_t>(number);
					return true;
				}

				default:
				{
					auto last_token = get_token_string();
					return sax->parse_error(chars_read, last_token, parse_error::create(113, chars_read, exception_message(input_format_t::ubjson, "expected length type specification (U, i, I, l, L) after '#'; last byte: 0x" + last_token, "size")));
				}
				}
			}

			/*!
			@brief determine the type and size for a container
			In the optimized UBJSON format, a type and a size can be provided to allow
			for a more compact representation.
			@param[out] result  pair of the size and the type
			@return whether pair creation completed
			*/
			bool get_ubjson_size_type(std::pair<std::size_t, int>& result)
			{
				result.first = string_t::npos; // size
				result.second = 0; // type

				get_ignore_noop();

				if (current == '$')
				{
					result.second = get();  // must not ignore 'N', because 'N' maybe the type
					if (JSON_HEDLEY_UNLIKELY(not unexpect_eof(input_format_t::ubjson, "type")))
					{
						return false;
					}

					get_ignore_noop();
					if (JSON_HEDLEY_UNLIKELY(current != '#'))
					{
						if (JSON_HEDLEY_UNLIKELY(not unexpect_eof(input_format_t::ubjson, "value")))
						{
							return false;
						}
						auto last_token = get_token_string();
						return sax->parse_error(chars_read, last_token, parse_error::create(112, chars_read, exception_message(input_format_t::ubjson, "expected '#' after type information; last byte: 0x" + last_token, "size")));
					}

					return get_ubjson_size_value(result.first);
				}

				if (current == '#')
				{
					return get_ubjson_size_value(result.first);
				}

				return true;
			}

			/*!
			@param prefix  the previously read or set type prefix
			@return whether value creation completed
			*/
			bool get_ubjson_value(const int prefix)
			{
				switch (prefix)
				{
				case std::char_traits<char>::eof():  // EOF
					return unexpect_eof(input_format_t::ubjson, "value");

				case 'T':  // true
					return sax->boolean(true);
				case 'F':  // false
					return sax->boolean(false);

				case 'Z':  // null
					return sax->null();

				case 'U':
				{
					std::uint8_t number;
					return get_number(input_format_t::ubjson, number) and sax->number_unsigned(number);
				}

				case 'i':
				{
					std::int8_t number;
					return get_number(input_format_t::ubjson, number) and sax->number_integer(number);
				}

				case 'I':
				{
					std::int16_t number;
					return get_number(input_format_t::ubjson, number) and sax->number_integer(number);
				}

				case 'l':
				{
					std::int32_t number;
					return get_number(input_format_t::ubjson, number) and sax->number_integer(number);
				}

				case 'L':
				{
					std::int64_t number;
					return get_number(input_format_t::ubjson, number) and sax->number_integer(number);
				}

				case 'd':
				{
					float number;
					return get_number(input_format_t::ubjson, number) and sax->number_float(static_cast<number_float_t>(number), "");
				}

				case 'D':
				{
					double number;
					return get_number(input_format_t::ubjson, number) and sax->number_float(static_cast<number_float_t>(number), "");
				}

				case 'C':  // char
				{
					get();
					if (JSON_HEDLEY_UNLIKELY(not unexpect_eof(input_format_t::ubjson, "char")))
					{
						return false;
					}
					if (JSON_HEDLEY_UNLIKELY(current > 127))
					{
						auto last_token = get_token_string();
						return sax->parse_error(chars_read, last_token, parse_error::create(113, chars_read, exception_message(input_format_t::ubjson, "byte after 'C' must be in range 0x00..0x7F; last byte: 0x" + last_token, "char")));
					}
					string_t s(1, static_cast<char>(current));
					return sax->string(s);
				}

				case 'S':  // string
				{
					string_t s;
					return get_ubjson_string(s) and sax->string(s);
				}

				case '[':  // array
					return get_ubjson_array();

				case '{':  // object
					return get_ubjson_object();

				default: // anything else
				{
					auto last_token = get_token_string();
					return sax->parse_error(chars_read, last_token, parse_error::create(112, chars_read, exception_message(input_format_t::ubjson, "invalid byte: 0x" + last_token, "value")));
				}
				}
			}

			/*!
			@return whether array creation completed
			*/
			bool get_ubjson_array()
			{
				std::pair<std::size_t, int> size_and_type;
				if (JSON_HEDLEY_UNLIKELY(not get_ubjson_size_type(size_and_type)))
				{
					return false;
				}

				if (size_and_type.first != string_t::npos)
				{
					if (JSON_HEDLEY_UNLIKELY(not sax->start_array(size_and_type.first)))
					{
						return false;
					}

					if (size_and_type.second != 0)
					{
						if (size_and_type.second != 'N')
						{
							for (std::size_t i = 0; i < size_and_type.first; ++i)
							{
								if (JSON_HEDLEY_UNLIKELY(not get_ubjson_value(size_and_type.second)))
								{
									return false;
								}
							}
						}
					}
					else
					{
						for (std::size_t i = 0; i < size_and_type.first; ++i)
						{
							if (JSON_HEDLEY_UNLIKELY(not parse_ubjson_internal()))
							{
								return false;
							}
						}
					}
				}
				else
				{
					if (JSON_HEDLEY_UNLIKELY(not sax->start_array(std::size_t(-1))))
					{
						return false;
					}

					while (current != ']')
					{
						if (JSON_HEDLEY_UNLIKELY(not parse_ubjson_internal(false)))
						{
							return false;
						}
						get_ignore_noop();
					}
				}

				return sax->end_array();
			}

			/*!
			@return whether object creation completed
			*/
			bool get_ubjson_object()
			{
				std::pair<std::size_t, int> size_and_type;
				if (JSON_HEDLEY_UNLIKELY(not get_ubjson_size_type(size_and_type)))
				{
					return false;
				}

				string_t key;
				if (size_and_type.first != string_t::npos)
				{
					if (JSON_HEDLEY_UNLIKELY(not sax->start_object(size_and_type.first)))
					{
						return false;
					}

					if (size_and_type.second != 0)
					{
						for (std::size_t i = 0; i < size_and_type.first; ++i)
						{
							if (JSON_HEDLEY_UNLIKELY(not get_ubjson_string(key) or not sax->key(key)))
							{
								return false;
							}
							if (JSON_HEDLEY_UNLIKELY(not get_ubjson_value(size_and_type.second)))
							{
								return false;
							}
							key.clear();
						}
					}
					else
					{
						for (std::size_t i = 0; i < size_and_type.first; ++i)
						{
							if (JSON_HEDLEY_UNLIKELY(not get_ubjson_string(key) or not sax->key(key)))
							{
								return false;
							}
							if (JSON_HEDLEY_UNLIKELY(not parse_ubjson_internal()))
							{
								return false;
							}
							key.clear();
						}
					}
				}
				else
				{
					if (JSON_HEDLEY_UNLIKELY(not sax->start_object(std::size_t(-1))))
					{
						return false;
					}

					while (current != '}')
					{
						if (JSON_HEDLEY_UNLIKELY(not get_ubjson_string(key, false) or not sax->key(key)))
						{
							return false;
						}
						if (JSON_HEDLEY_UNLIKELY(not parse_ubjson_internal()))
						{
							return false;
						}
						get_ignore_noop();
						key.clear();
					}
				}

				return sax->end_object();
			}

			///////////////////////
			// Utility functions //
			///////////////////////

			/*!
			@brief get next character from the input
			This function provides the interface to the used input adapter. It does
			not throw in case the input reached EOF, but returns a -'ve valued
			`std::char_traits<char>::eof()` in that case.
			@return character read from the input
			*/
			int get()
			{
				++chars_read;
				return current = ia->get_character();
			}

			/*!
			@return character read from the input after ignoring all 'N' entries
			*/
			int get_ignore_noop()
			{
				do
				{
					get();
				} while (current == 'N');

				return current;
			}

			/*
			@brief read a number from the input
			@tparam NumberType the type of the number
			@param[in] format   the current format (for diagnostics)
			@param[out] result  number of type @a NumberType
			@return whether conversion completed
			@note This function needs to respect the system's endianess, because
				  bytes in CBOR, MessagePack, and UBJSON are stored in network order
				  (big endian) and therefore need reordering on little endian systems.
			*/
			template<typename NumberType, bool InputIsLittleEndian = false>
			bool get_number(const input_format_t format, NumberType& result)
			{
				// step 1: read input into array with system's byte order
				std::array<std::uint8_t, sizeof(NumberType)> vec;
				for (std::size_t i = 0; i < sizeof(NumberType); ++i)
				{
					get();
					if (JSON_HEDLEY_UNLIKELY(not unexpect_eof(format, "number")))
					{
						return false;
					}

					// reverse byte order prior to conversion if necessary
					if (is_little_endian != InputIsLittleEndian)
					{
						vec[sizeof(NumberType) - i - 1] = static_cast<std::uint8_t>(current);
					}
					else
					{
						vec[i] = static_cast<std::uint8_t>(current); // LCOV_EXCL_LINE
					}
				}

				// step 2: convert array into number of type T and return
				std::memcpy(&result, vec.data(), sizeof(NumberType));
				return true;
			}

			/*!
			@brief create a string by reading characters from the input
			@tparam NumberType the type of the number
			@param[in] format the current format (for diagnostics)
			@param[in] len number of characters to read
			@param[out] result string created by reading @a len bytes
			@return whether string creation completed
			@note We can not reserve @a len bytes for the result, because @a len
				  may be too large. Usually, @ref unexpect_eof() detects the end of
				  the input before we run out of string memory.
			*/
			template<typename NumberType>
			bool get_string(const input_format_t format,
				const NumberType len,
				string_t& result)
			{
				bool success = true;
				std::generate_n(std::back_inserter(result), len, [this, &success, &format]()
					{
						get();
						if (JSON_HEDLEY_UNLIKELY(not unexpect_eof(format, "string")))
						{
							success = false;
						}
						return static_cast<char>(current);
					});
				return success;
			}

			/*!
			@param[in] format   the current format (for diagnostics)
			@param[in] context  further context information (for diagnostics)
			@return whether the last read character is not EOF
			*/
			JSON_HEDLEY_NON_NULL(3)
				bool unexpect_eof(const input_format_t format, const char* context) const
			{
				if (JSON_HEDLEY_UNLIKELY(current == std::char_traits<char>::eof()))
				{
					return sax->parse_error(chars_read, "<end of file>",
						parse_error::create(110, chars_read, exception_message(format, "unexpected end of input", context)));
				}
				return true;
			}

			/*!
			@return a string representation of the last read byte
			*/
			std::string get_token_string() const
			{
				std::array<char, 3> cr{ {} };
				(std::snprintf)(cr.data(), cr.size(), "%.2hhX", static_cast<unsigned char>(current));
				return std::string{ cr.data() };
			}

			/*!
			@param[in] format   the current format
			@param[in] detail   a detailed error message
			@param[in] context  further contect information
			@return a message string to use in the parse_error exceptions
			*/
			std::string exception_message(const input_format_t format,
				const std::string& detail,
				const std::string& context) const
			{
				std::string error_msg = "syntax error while parsing ";

				switch (format)
				{
				case input_format_t::cbor:
					error_msg += "CBOR";
					break;

				case input_format_t::msgpack:
					error_msg += "MessagePack";
					break;

				case input_format_t::ubjson:
					error_msg += "UBJSON";
					break;

				case input_format_t::bson:
					error_msg += "BSON";
					break;

				default:            // LCOV_EXCL_LINE
					assert(false);  // LCOV_EXCL_LINE
				}

				return error_msg + " " + context + ": " + detail;
			}

		private:
			/// input adapter
			input_adapter_t ia = nullptr;

			/// the current character
			int current = std::char_traits<char>::eof();

			/// the number of characters read
			std::size_t chars_read = 0;

			/// whether we can assume little endianess
			const bool is_little_endian = little_endianess();

			/// the SAX parser
			json_sax_t* sax = nullptr;
		};
	}  // namespace detail
}  // namespace nlohmann

// #include <nlohmann/detail/input/input_adapters.hpp>

// #include <nlohmann/detail/input/lexer.hpp>


#include <array> // array
#include <clocale> // localeconv
#include <cstddef> // size_t
#include <cstdio> // snprintf
#include <cstdlib> // strtof, strtod, strtold, strtoll, strtoull
#include <initializer_list> // initializer_list
#include <string> // char_traits, string
#include <utility> // move
#include <vector> // vector

// #include <nlohmann/detail/input/input_adapters.hpp>

// #include <nlohmann/detail/input/position_t.hpp>

// #include <nlohmann/detail/macro_scope.hpp>


namespace nlohmann
{
	namespace detail
	{
		///////////
		// lexer //
		///////////

		/*!
		@brief lexical analysis
		This class organizes the lexical analysis during JSON deserialization.
		*/
		template<typename BasicJsonType>
		class lexer
		{
			using number_integer_t = typename BasicJsonType::number_integer_t;
			using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
			using number_float_t = typename BasicJsonType::number_float_t;
			using string_t = typename BasicJsonType::string_t;

		public:
			/// token types for the parser
			enum class token_type
			{
				uninitialized,    ///< indicating the scanner is uninitialized
				literal_true,     ///< the `true` literal
				literal_false,    ///< the `false` literal
				literal_null,     ///< the `null` literal
				value_string,     ///< a string -- use get_string() for actual value
				value_unsigned,   ///< an unsigned integer -- use get_number_unsigned() for actual value
				value_integer,    ///< a signed integer -- use get_number_integer() for actual value
				value_float,      ///< an floating point number -- use get_number_float() for actual value
				begin_array,      ///< the character for array begin `[`
				begin_object,     ///< the character for object begin `{`
				end_array,        ///< the character for array end `]`
				end_object,       ///< the character for object end `}`
				name_separator,   ///< the name separator `:`
				value_separator,  ///< the value separator `,`
				parse_error,      ///< indicating a parse error
				end_of_input,     ///< indicating the end of the input buffer
				literal_or_value  ///< a literal or the begin of a value (only for diagnostics)
			};

			/// return name of values of type token_type (only used for errors)
			JSON_HEDLEY_RETURNS_NON_NULL
				JSON_HEDLEY_CONST
				static const char* token_type_name(const token_type t) noexcept
			{
				switch (t)
				{
				case token_type::uninitialized:
					return "<uninitialized>";
				case token_type::literal_true:
					return "true literal";
				case token_type::literal_false:
					return "false literal";
				case token_type::literal_null:
					return "null literal";
				case token_type::value_string:
					return "string literal";
				case lexer::token_type::value_unsigned:
				case lexer::token_type::value_integer:
				case lexer::token_type::value_float:
					return "number literal";
				case token_type::begin_array:
					return "'['";
				case token_type::begin_object:
					return "'{'";
				case token_type::end_array:
					return "']'";
				case token_type::end_object:
					return "'}'";
				case token_type::name_separator:
					return "':'";
				case token_type::value_separator:
					return "','";
				case token_type::parse_error:
					return "<parse error>";
				case token_type::end_of_input:
					return "end of input";
				case token_type::literal_or_value:
					return "'[', '{', or a literal";
					// LCOV_EXCL_START
				default: // catch non-enum values
					return "unknown token";
					// LCOV_EXCL_STOP
				}
			}

			explicit lexer(detail::input_adapter_t&& adapter)
				: ia(std::move(adapter)), decimal_point_char(get_decimal_point()) {}

			// delete because of pointer members
			lexer(const lexer&) = delete;
			lexer(lexer&&) = delete;
			lexer& operator=(lexer&) = delete;
			lexer& operator=(lexer&&) = delete;
			~lexer() = default;

		private:
			/////////////////////
			// locales
			/////////////////////

			/// return the locale-dependent decimal point
			JSON_HEDLEY_PURE
				static char get_decimal_point() noexcept
			{
				const auto loc = localeconv();
				assert(loc != nullptr);
				return (loc->decimal_point == nullptr) ? '.' : *(loc->decimal_point);
			}

			/////////////////////
			// scan functions
			/////////////////////

			/*!
			@brief get codepoint from 4 hex characters following `\u`
			For input "\u c1 c2 c3 c4" the codepoint is:
			  (c1 * 0x1000) + (c2 * 0x0100) + (c3 * 0x0010) + c4
			= (c1 << 12) + (c2 << 8) + (c3 << 4) + (c4 << 0)
			Furthermore, the possible characters '0'..'9', 'A'..'F', and 'a'..'f'
			must be converted to the integers 0x0..0x9, 0xA..0xF, 0xA..0xF, resp. The
			conversion is done by subtracting the offset (0x30, 0x37, and 0x57)
			between the ASCII value of the character and the desired integer value.
			@return codepoint (0x0000..0xFFFF) or -1 in case of an error (e.g. EOF or
					non-hex character)
			*/
			int get_codepoint()
			{
				// this function only makes sense after reading `\u`
				assert(current == 'u');
				int codepoint = 0;

				const auto factors = { 12u, 8u, 4u, 0u };
				for (const auto factor : factors)
				{
					get();

					if (current >= '0' and current <= '9')
					{
						codepoint += static_cast<int>((static_cast<unsigned int>(current) - 0x30u) << factor);
					}
					else if (current >= 'A' and current <= 'F')
					{
						codepoint += static_cast<int>((static_cast<unsigned int>(current) - 0x37u) << factor);
					}
					else if (current >= 'a' and current <= 'f')
					{
						codepoint += static_cast<int>((static_cast<unsigned int>(current) - 0x57u) << factor);
					}
					else
					{
						return -1;
					}
				}

				assert(0x0000 <= codepoint and codepoint <= 0xFFFF);
				return codepoint;
			}

			/*!
			@brief check if the next byte(s) are inside a given range
			Adds the current byte and, for each passed range, reads a new byte and
			checks if it is inside the range. If a violation was detected, set up an
			error message and return false. Otherwise, return true.
			@param[in] ranges  list of integers; interpreted as list of pairs of
							   inclusive lower and upper bound, respectively
			@pre The passed list @a ranges must have 2, 4, or 6 elements; that is,
				 1, 2, or 3 pairs. This precondition is enforced by an assertion.
			@return true if and only if no range violation was detected
			*/
			bool next_byte_in_range(std::initializer_list<int> ranges)
			{
				assert(ranges.size() == 2 or ranges.size() == 4 or ranges.size() == 6);
				add(current);

				for (auto range = ranges.begin(); range != ranges.end(); ++range)
				{
					get();
					if (JSON_HEDLEY_LIKELY(*range <= current and current <= *(++range)))
					{
						add(current);
					}
					else
					{
						error_message = "invalid string: ill-formed UTF-8 byte";
						return false;
					}
				}

				return true;
			}

			/*!
			@brief scan a string literal
			This function scans a string according to Sect. 7 of RFC 7159. While
			scanning, bytes are escaped and copied into buffer token_buffer. Then the
			function returns successfully, token_buffer is *not* null-terminated (as it
			may contain \0 bytes), and token_buffer.size() is the number of bytes in the
			string.
			@return token_type::value_string if string could be successfully scanned,
					token_type::parse_error otherwise
			@note In case of errors, variable error_message contains a textual
				  description.
			*/
			token_type scan_string()
			{
				// reset token_buffer (ignore opening quote)
				reset();

				// we entered the function by reading an open quote
				assert(current == '\"');

				while (true)
				{
					// get next character
					switch (get())
					{
						// end of file while parsing string
					case std::char_traits<char>::eof():
					{
						error_message = "invalid string: missing closing quote";
						return token_type::parse_error;
					}

					// closing quote
					case '\"':
					{
						return token_type::value_string;
					}

					// escapes
					case '\\':
					{
						switch (get())
						{
							// quotation mark
						case '\"':
							add('\"');
							break;
							// reverse solidus
						case '\\':
							add('\\');
							break;
							// solidus
						case '/':
							add('/');
							break;
							// backspace
						case 'b':
							add('\b');
							break;
							// form feed
						case 'f':
							add('\f');
							break;
							// line feed
						case 'n':
							add('\n');
							break;
							// carriage return
						case 'r':
							add('\r');
							break;
							// tab
						case 't':
							add('\t');
							break;

							// unicode escapes
						case 'u':
						{
							const int codepoint1 = get_codepoint();
							int codepoint = codepoint1; // start with codepoint1

							if (JSON_HEDLEY_UNLIKELY(codepoint1 == -1))
							{
								error_message = "invalid string: '\\u' must be followed by 4 hex digits";
								return token_type::parse_error;
							}

							// check if code point is a high surrogate
							if (0xD800 <= codepoint1 and codepoint1 <= 0xDBFF)
							{
								// expect next \uxxxx entry
								if (JSON_HEDLEY_LIKELY(get() == '\\' and get() == 'u'))
								{
									const int codepoint2 = get_codepoint();

									if (JSON_HEDLEY_UNLIKELY(codepoint2 == -1))
									{
										error_message = "invalid string: '\\u' must be followed by 4 hex digits";
										return token_type::parse_error;
									}

									// check if codepoint2 is a low surrogate
									if (JSON_HEDLEY_LIKELY(0xDC00 <= codepoint2 and codepoint2 <= 0xDFFF))
									{
										// overwrite codepoint
										codepoint = static_cast<int>(
											// high surrogate occupies the most significant 22 bits
											(static_cast<unsigned int>(codepoint1) << 10u)
											// low surrogate occupies the least significant 15 bits
											+ static_cast<unsigned int>(codepoint2)
											// there is still the 0xD800, 0xDC00 and 0x10000 noise
											// in the result so we have to subtract with:
											// (0xD800 << 10) + DC00 - 0x10000 = 0x35FDC00
											-0x35FDC00u);
									}
									else
									{
										error_message = "invalid string: surrogate U+DC00..U+DFFF must be followed by U+DC00..U+DFFF";
										return token_type::parse_error;
									}
								}
								else
								{
									error_message = "invalid string: surrogate U+DC00..U+DFFF must be followed by U+DC00..U+DFFF";
									return token_type::parse_error;
								}
							}
							else
							{
								if (JSON_HEDLEY_UNLIKELY(0xDC00 <= codepoint1 and codepoint1 <= 0xDFFF))
								{
									error_message = "invalid string: surrogate U+DC00..U+DFFF must follow U+D800..U+DBFF";
									return token_type::parse_error;
								}
							}

							// result of the above calculation yields a proper codepoint
							assert(0x00 <= codepoint and codepoint <= 0x10FFFF);

							// translate codepoint into bytes
							if (codepoint < 0x80)
							{
								// 1-byte characters: 0xxxxxxx (ASCII)
								add(codepoint);
							}
							else if (codepoint <= 0x7FF)
							{
								// 2-byte characters: 110xxxxx 10xxxxxx
								add(static_cast<int>(0xC0u | (static_cast<unsigned int>(codepoint) >> 6u)));
								add(static_cast<int>(0x80u | (static_cast<unsigned int>(codepoint) & 0x3Fu)));
							}
							else if (codepoint <= 0xFFFF)
							{
								// 3-byte characters: 1110xxxx 10xxxxxx 10xxxxxx
								add(static_cast<int>(0xE0u | (static_cast<unsigned int>(codepoint) >> 12u)));
								add(static_cast<int>(0x80u | ((static_cast<unsigned int>(codepoint) >> 6u) & 0x3Fu)));
								add(static_cast<int>(0x80u | (static_cast<unsigned int>(codepoint) & 0x3Fu)));
							}
							else
							{
								// 4-byte characters: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
								add(static_cast<int>(0xF0u | (static_cast<unsigned int>(codepoint) >> 18u)));
								add(static_cast<int>(0x80u | ((static_cast<unsigned int>(codepoint) >> 12u) & 0x3Fu)));
								add(static_cast<int>(0x80u | ((static_cast<unsigned int>(codepoint) >> 6u) & 0x3Fu)));
								add(static_cast<int>(0x80u | (static_cast<unsigned int>(codepoint) & 0x3Fu)));
							}

							break;
						}

						// other characters after escape
						default:
							error_message = "invalid string: forbidden character after backslash";
							return token_type::parse_error;
						}

						break;
					}

					// invalid control characters
					case 0x00:
					{
						error_message = "invalid string: control character U+0000 (NUL) must be escaped to \\u0000";
						return token_type::parse_error;
					}

					case 0x01:
					{
						error_message = "invalid string: control character U+0001 (SOH) must be escaped to \\u0001";
						return token_type::parse_error;
					}

					case 0x02:
					{
						error_message = "invalid string: control character U+0002 (STX) must be escaped to \\u0002";
						return token_type::parse_error;
					}

					case 0x03:
					{
						error_message = "invalid string: control character U+0003 (ETX) must be escaped to \\u0003";
						return token_type::parse_error;
					}

					case 0x04:
					{
						error_message = "invalid string: control character U+0004 (EOT) must be escaped to \\u0004";
						return token_type::parse_error;
					}

					case 0x05:
					{
						error_message = "invalid string: control character U+0005 (ENQ) must be escaped to \\u0005";
						return token_type::parse_error;
					}

					case 0x06:
					{
						error_message = "invalid string: control character U+0006 (ACK) must be escaped to \\u0006";
						return token_type::parse_error;
					}

					case 0x07:
					{
						error_message = "invalid string: control character U+0007 (BEL) must be escaped to \\u0007";
						return token_type::parse_error;
					}

					case 0x08:
					{
						error_message = "invalid string: control character U+0008 (BS) must be escaped to \\u0008 or \\b";
						return token_type::parse_error;
					}

					case 0x09:
					{
						error_message = "invalid string: control character U+0009 (HT) must be escaped to \\u0009 or \\t";
						return token_type::parse_error;
					}

					case 0x0A:
					{
						error_message = "invalid string: control character U+000A (LF) must be escaped to \\u000A or \\n";
						return token_type::parse_error;
					}

					case 0x0B:
					{
						error_message = "invalid string: control character U+000B (VT) must be escaped to \\u000B";
						return token_type::parse_error;
					}

					case 0x0C:
					{
						error_message = "invalid string: control character U+000C (FF) must be escaped to \\u000C or \\f";
						return token_type::parse_error;
					}

					case 0x0D:
					{
						error_message = "invalid string: control character U+000D (CR) must be escaped to \\u000D or \\r";
						return token_type::parse_error;
					}

					case 0x0E:
					{
						error_message = "invalid string: control character U+000E (SO) must be escaped to \\u000E";
						return token_type::parse_error;
					}

					case 0x0F:
					{
						error_message = "invalid string: control character U+000F (SI) must be escaped to \\u000F";
						return token_type::parse_error;
					}

					case 0x10:
					{
						error_message = "invalid string: control character U+0010 (DLE) must be escaped to \\u0010";
						return token_type::parse_error;
					}

					case 0x11:
					{
						error_message = "invalid string: control character U+0011 (DC1) must be escaped to \\u0011";
						return token_type::parse_error;
					}

					case 0x12:
					{
						error_message = "invalid string: control character U+0012 (DC2) must be escaped to \\u0012";
						return token_type::parse_error;
					}

					case 0x13:
					{
						error_message = "invalid string: control character U+0013 (DC3) must be escaped to \\u0013";
						return token_type::parse_error;
					}

					case 0x14:
					{
						error_message = "invalid string: control character U+0014 (DC4) must be escaped to \\u0014";
						return token_type::parse_error;
					}

					case 0x15:
					{
						error_message = "invalid string: control character U+0015 (NAK) must be escaped to \\u0015";
						return token_type::parse_error;
					}

					case 0x16:
					{
						error_message = "invalid string: control character U+0016 (SYN) must be escaped to \\u0016";
						return token_type::parse_error;
					}

					case 0x17:
					{
						error_message = "invalid string: control character U+0017 (ETB) must be escaped to \\u0017";
						return token_type::parse_error;
					}

					case 0x18:
					{
						error_message = "invalid string: control character U+0018 (CAN) must be escaped to \\u0018";
						return token_type::parse_error;
					}

					case 0x19:
					{
						error_message = "invalid string: control character U+0019 (EM) must be escaped to \\u0019";
						return token_type::parse_error;
					}

					case 0x1A:
					{
						error_message = "invalid string: control character U+001A (SUB) must be escaped to \\u001A";
						return token_type::parse_error;
					}

					case 0x1B:
					{
						error_message = "invalid string: control character U+001B (ESC) must be escaped to \\u001B";
						return token_type::parse_error;
					}

					case 0x1C:
					{
						error_message = "invalid string: control character U+001C (FS) must be escaped to \\u001C";
						return token_type::parse_error;
					}

					case 0x1D:
					{
						error_message = "invalid string: control character U+001D (GS) must be escaped to \\u001D";
						return token_type::parse_error;
					}

					case 0x1E:
					{
						error_message = "invalid string: control character U+001E (RS) must be escaped to \\u001E";
						return token_type::parse_error;
					}

					case 0x1F:
					{
						error_message = "invalid string: control character U+001F (US) must be escaped to \\u001F";
						return token_type::parse_error;
					}

					// U+0020..U+007F (except U+0022 (quote) and U+005C (backspace))
					case 0x20:
					case 0x21:
					case 0x23:
					case 0x24:
					case 0x25:
					case 0x26:
					case 0x27:
					case 0x28:
					case 0x29:
					case 0x2A:
					case 0x2B:
					case 0x2C:
					case 0x2D:
					case 0x2E:
					case 0x2F:
					case 0x30:
					case 0x31:
					case 0x32:
					case 0x33:
					case 0x34:
					case 0x35:
					case 0x36:
					case 0x37:
					case 0x38:
					case 0x39:
					case 0x3A:
					case 0x3B:
					case 0x3C:
					case 0x3D:
					case 0x3E:
					case 0x3F:
					case 0x40:
					case 0x41:
					case 0x42:
					case 0x43:
					case 0x44:
					case 0x45:
					case 0x46:
					case 0x47:
					case 0x48:
					case 0x49:
					case 0x4A:
					case 0x4B:
					case 0x4C:
					case 0x4D:
					case 0x4E:
					case 0x4F:
					case 0x50:
					case 0x51:
					case 0x52:
					case 0x53:
					case 0x54:
					case 0x55:
					case 0x56:
					case 0x57:
					case 0x58:
					case 0x59:
					case 0x5A:
					case 0x5B:
					case 0x5D:
					case 0x5E:
					case 0x5F:
					case 0x60:
					case 0x61:
					case 0x62:
					case 0x63:
					case 0x64:
					case 0x65:
					case 0x66:
					case 0x67:
					case 0x68:
					case 0x69:
					case 0x6A:
					case 0x6B:
					case 0x6C:
					case 0x6D:
					case 0x6E:
					case 0x6F:
					case 0x70:
					case 0x71:
					case 0x72:
					case 0x73:
					case 0x74:
					case 0x75:
					case 0x76:
					case 0x77:
					case 0x78:
					case 0x79:
					case 0x7A:
					case 0x7B:
					case 0x7C:
					case 0x7D:
					case 0x7E:
					case 0x7F:
					{
						add(current);
						break;
					}

					// U+0080..U+07FF: bytes C2..DF 80..BF
					case 0xC2:
					case 0xC3:
					case 0xC4:
					case 0xC5:
					case 0xC6:
					case 0xC7:
					case 0xC8:
					case 0xC9:
					case 0xCA:
					case 0xCB:
					case 0xCC:
					case 0xCD:
					case 0xCE:
					case 0xCF:
					case 0xD0:
					case 0xD1:
					case 0xD2:
					case 0xD3:
					case 0xD4:
					case 0xD5:
					case 0xD6:
					case 0xD7:
					case 0xD8:
					case 0xD9:
					case 0xDA:
					case 0xDB:
					case 0xDC:
					case 0xDD:
					case 0xDE:
					case 0xDF:
					{
						if (JSON_HEDLEY_UNLIKELY(not next_byte_in_range({ 0x80, 0xBF })))
						{
							return token_type::parse_error;
						}
						break;
					}

					// U+0800..U+0FFF: bytes E0 A0..BF 80..BF
					case 0xE0:
					{
						if (JSON_HEDLEY_UNLIKELY(not (next_byte_in_range({ 0xA0, 0xBF, 0x80, 0xBF }))))
						{
							return token_type::parse_error;
						}
						break;
					}

					// U+1000..U+CFFF: bytes E1..EC 80..BF 80..BF
					// U+E000..U+FFFF: bytes EE..EF 80..BF 80..BF
					case 0xE1:
					case 0xE2:
					case 0xE3:
					case 0xE4:
					case 0xE5:
					case 0xE6:
					case 0xE7:
					case 0xE8:
					case 0xE9:
					case 0xEA:
					case 0xEB:
					case 0xEC:
					case 0xEE:
					case 0xEF:
					{
						if (JSON_HEDLEY_UNLIKELY(not (next_byte_in_range({ 0x80, 0xBF, 0x80, 0xBF }))))
						{
							return token_type::parse_error;
						}
						break;
					}

					// U+D000..U+D7FF: bytes ED 80..9F 80..BF
					case 0xED:
					{
						if (JSON_HEDLEY_UNLIKELY(not (next_byte_in_range({ 0x80, 0x9F, 0x80, 0xBF }))))
						{
							return token_type::parse_error;
						}
						break;
					}

					// U+10000..U+3FFFF F0 90..BF 80..BF 80..BF
					case 0xF0:
					{
						if (JSON_HEDLEY_UNLIKELY(not (next_byte_in_range({ 0x90, 0xBF, 0x80, 0xBF, 0x80, 0xBF }))))
						{
							return token_type::parse_error;
						}
						break;
					}

					// U+40000..U+FFFFF F1..F3 80..BF 80..BF 80..BF
					case 0xF1:
					case 0xF2:
					case 0xF3:
					{
						if (JSON_HEDLEY_UNLIKELY(not (next_byte_in_range({ 0x80, 0xBF, 0x80, 0xBF, 0x80, 0xBF }))))
						{
							return token_type::parse_error;
						}
						break;
					}

					// U+100000..U+10FFFF F4 80..8F 80..BF 80..BF
					case 0xF4:
					{
						if (JSON_HEDLEY_UNLIKELY(not (next_byte_in_range({ 0x80, 0x8F, 0x80, 0xBF, 0x80, 0xBF }))))
						{
							return token_type::parse_error;
						}
						break;
					}

					// remaining bytes (80..C1 and F5..FF) are ill-formed
					default:
					{
						error_message = "invalid string: ill-formed UTF-8 byte";
						return token_type::parse_error;
					}
					}
				}
			}

			JSON_HEDLEY_NON_NULL(2)
				static void strtof(float& f, const char* str, char** endptr) noexcept
			{
				f = std::strtof(str, endptr);
			}

			JSON_HEDLEY_NON_NULL(2)
				static void strtof(double& f, const char* str, char** endptr) noexcept
			{
				f = std::strtod(str, endptr);
			}

			JSON_HEDLEY_NON_NULL(2)
				static void strtof(long double& f, const char* str, char** endptr) noexcept
			{
				f = std::strtold(str, endptr);
			}

			/*!
			@brief scan a number literal
			This function scans a string according to Sect. 6 of RFC 7159.
			The function is realized with a deterministic finite state machine derived
			from the grammar described in RFC 7159. Starting in state "init", the
			input is read and used to determined the next state. Only state "done"
			accepts the number. State "error" is a trap state to model errors. In the
			table below, "anything" means any character but the ones listed before.
			state    | 0        | 1-9      | e E      | +       | -       | .        | anything
			---------|----------|----------|----------|---------|---------|----------|-----------
			init     | zero     | any1     | [error]  | [error] | minus   | [error]  | [error]
			minus    | zero     | any1     | [error]  | [error] | [error] | [error]  | [error]
			zero     | done     | done     | exponent | done    | done    | decimal1 | done
			any1     | any1     | any1     | exponent | done    | done    | decimal1 | done
			decimal1 | decimal2 | [error]  | [error]  | [error] | [error] | [error]  | [error]
			decimal2 | decimal2 | decimal2 | exponent | done    | done    | done     | done
			exponent | any2     | any2     | [error]  | sign    | sign    | [error]  | [error]
			sign     | any2     | any2     | [error]  | [error] | [error] | [error]  | [error]
			any2     | any2     | any2     | done     | done    | done    | done     | done
			The state machine is realized with one label per state (prefixed with
			"scan_number_") and `goto` statements between them. The state machine
			contains cycles, but any cycle can be left when EOF is read. Therefore,
			the function is guaranteed to terminate.
			During scanning, the read bytes are stored in token_buffer. This string is
			then converted to a signed integer, an unsigned integer, or a
			floating-point number.
			@return token_type::value_unsigned, token_type::value_integer, or
					token_type::value_float if number could be successfully scanned,
					token_type::parse_error otherwise
			@note The scanner is independent of the current locale. Internally, the
				  locale's decimal point is used instead of `.` to work with the
				  locale-dependent converters.
			*/
			token_type scan_number()  // lgtm [cpp/use-of-goto]
			{
				// reset token_buffer to store the number's bytes
				reset();

				// the type of the parsed number; initially set to unsigned; will be
				// changed if minus sign, decimal point or exponent is read
				token_type number_type = token_type::value_unsigned;

				// state (init): we just found out we need to scan a number
				switch (current)
				{
				case '-':
				{
					add(current);
					goto scan_number_minus;
				}

				case '0':
				{
					add(current);
					goto scan_number_zero;
				}

				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
				{
					add(current);
					goto scan_number_any1;
				}

				// all other characters are rejected outside scan_number()
				default:            // LCOV_EXCL_LINE
					assert(false);  // LCOV_EXCL_LINE
				}

			scan_number_minus:
				// state: we just parsed a leading minus sign
				number_type = token_type::value_integer;
				switch (get())
				{
				case '0':
				{
					add(current);
					goto scan_number_zero;
				}

				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
				{
					add(current);
					goto scan_number_any1;
				}

				default:
				{
					error_message = "invalid number; expected digit after '-'";
					return token_type::parse_error;
				}
				}

			scan_number_zero:
				// state: we just parse a zero (maybe with a leading minus sign)
				switch (get())
				{
				case '.':
				{
					add(decimal_point_char);
					goto scan_number_decimal1;
				}

				case 'e':
				case 'E':
				{
					add(current);
					goto scan_number_exponent;
				}

				default:
					goto scan_number_done;
				}

			scan_number_any1:
				// state: we just parsed a number 0-9 (maybe with a leading minus sign)
				switch (get())
				{
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
				{
					add(current);
					goto scan_number_any1;
				}

				case '.':
				{
					add(decimal_point_char);
					goto scan_number_decimal1;
				}

				case 'e':
				case 'E':
				{
					add(current);
					goto scan_number_exponent;
				}

				default:
					goto scan_number_done;
				}

			scan_number_decimal1:
				// state: we just parsed a decimal point
				number_type = token_type::value_float;
				switch (get())
				{
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
				{
					add(current);
					goto scan_number_decimal2;
				}

				default:
				{
					error_message = "invalid number; expected digit after '.'";
					return token_type::parse_error;
				}
				}

			scan_number_decimal2:
				// we just parsed at least one number after a decimal point
				switch (get())
				{
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
				{
					add(current);
					goto scan_number_decimal2;
				}

				case 'e':
				case 'E':
				{
					add(current);
					goto scan_number_exponent;
				}

				default:
					goto scan_number_done;
				}

			scan_number_exponent:
				// we just parsed an exponent
				number_type = token_type::value_float;
				switch (get())
				{
				case '+':
				case '-':
				{
					add(current);
					goto scan_number_sign;
				}

				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
				{
					add(current);
					goto scan_number_any2;
				}

				default:
				{
					error_message =
						"invalid number; expected '+', '-', or digit after exponent";
					return token_type::parse_error;
				}
				}

			scan_number_sign:
				// we just parsed an exponent sign
				switch (get())
				{
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
				{
					add(current);
					goto scan_number_any2;
				}

				default:
				{
					error_message = "invalid number; expected digit after exponent sign";
					return token_type::parse_error;
				}
				}

			scan_number_any2:
				// we just parsed a number after the exponent or exponent sign
				switch (get())
				{
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
				{
					add(current);
					goto scan_number_any2;
				}

				default:
					goto scan_number_done;
				}

			scan_number_done:
				// unget the character after the number (we only read it to know that
				// we are done scanning a number)
				unget();

				char* endptr = nullptr;
				errno = 0;

				// try to parse integers first and fall back to floats
				if (number_type == token_type::value_unsigned)
				{
					const auto x = std::strtoull(token_buffer.data(), &endptr, 10);

					// we checked the number format before
					assert(endptr == token_buffer.data() + token_buffer.size());

					if (errno == 0)
					{
						value_unsigned = static_cast<number_unsigned_t>(x);
						if (value_unsigned == x)
						{
							return token_type::value_unsigned;
						}
					}
				}
				else if (number_type == token_type::value_integer)
				{
					const auto x = std::strtoll(token_buffer.data(), &endptr, 10);

					// we checked the number format before
					assert(endptr == token_buffer.data() + token_buffer.size());

					if (errno == 0)
					{
						value_integer = static_cast<number_integer_t>(x);
						if (value_integer == x)
						{
							return token_type::value_integer;
						}
					}
				}

				// this code is reached if we parse a floating-point number or if an
				// integer conversion above failed
				strtof(value_float, token_buffer.data(), &endptr);

				// we checked the number format before
				assert(endptr == token_buffer.data() + token_buffer.size());

				return token_type::value_float;
			}

			/*!
			@param[in] literal_text  the literal text to expect
			@param[in] length        the length of the passed literal text
			@param[in] return_type   the token type to return on success
			*/
			JSON_HEDLEY_NON_NULL(2)
				token_type scan_literal(const char* literal_text, const std::size_t length,
					token_type return_type)
			{
				assert(current == literal_text[0]);
				for (std::size_t i = 1; i < length; ++i)
				{
					if (JSON_HEDLEY_UNLIKELY(get() != literal_text[i]))
					{
						error_message = "invalid literal";
						return token_type::parse_error;
					}
				}
				return return_type;
			}

			/////////////////////
			// input management
			/////////////////////

			/// reset token_buffer; current character is beginning of token
			void reset() noexcept
			{
				token_buffer.clear();
				token_string.clear();
				token_string.push_back(std::char_traits<char>::to_char_type(current));
			}

			/*
			@brief get next character from the input
			This function provides the interface to the used input adapter. It does
			not throw in case the input reached EOF, but returns a
			`std::char_traits<char>::eof()` in that case.  Stores the scanned characters
			for use in error messages.
			@return character read from the input
			*/
			std::char_traits<char>::int_type get()
			{
				++position.chars_read_total;
				++position.chars_read_current_line;

				if (next_unget)
				{
					// just reset the next_unget variable and work with current
					next_unget = false;
				}
				else
				{
					current = ia->get_character();
				}

				if (JSON_HEDLEY_LIKELY(current != std::char_traits<char>::eof()))
				{
					token_string.push_back(std::char_traits<char>::to_char_type(current));
				}

				if (current == '\n')
				{
					++position.lines_read;
					position.chars_read_current_line = 0;
				}

				return current;
			}

			/*!
			@brief unget current character (read it again on next get)
			We implement unget by setting variable next_unget to true. The input is not
			changed - we just simulate ungetting by modifying chars_read_total,
			chars_read_current_line, and token_string. The next call to get() will
			behave as if the unget character is read again.
			*/
			void unget()
			{
				next_unget = true;

				--position.chars_read_total;

				// in case we "unget" a newline, we have to also decrement the lines_read
				if (position.chars_read_current_line == 0)
				{
					if (position.lines_read > 0)
					{
						--position.lines_read;
					}
				}
				else
				{
					--position.chars_read_current_line;
				}

				if (JSON_HEDLEY_LIKELY(current != std::char_traits<char>::eof()))
				{
					assert(not token_string.empty());
					token_string.pop_back();
				}
			}

			/// add a character to token_buffer
			void add(int c)
			{
				token_buffer.push_back(std::char_traits<char>::to_char_type(c));
			}

		public:
			/////////////////////
			// value getters
			/////////////////////

			/// return integer value
			constexpr number_integer_t get_number_integer() const noexcept
			{
				return value_integer;
			}

			/// return unsigned integer value
			constexpr number_unsigned_t get_number_unsigned() const noexcept
			{
				return value_unsigned;
			}

			/// return floating-point value
			constexpr number_float_t get_number_float() const noexcept
			{
				return value_float;
			}

			/// return current string value (implicitly resets the token; useful only once)
			string_t& get_string()
			{
				return token_buffer;
			}

			/////////////////////
			// diagnostics
			/////////////////////

			/// return position of last read token
			constexpr position_t get_position() const noexcept
			{
				return position;
			}

			/// return the last read token (for errors only).  Will never contain EOF
			/// (an arbitrary value that is not a valid char value, often -1), because
			/// 255 may legitimately occur.  May contain NUL, which should be escaped.
			std::string get_token_string() const
			{
				// escape control characters
				std::string result;
				for (const auto c : token_string)
				{
					if ('\x00' <= c and c <= '\x1F')
					{
						// escape control characters
						std::array<char, 9> cs{ {} };
						(std::snprintf)(cs.data(), cs.size(), "<U+%.4X>", static_cast<unsigned char>(c));
						result += cs.data();
					}
					else
					{
						// add character as is
						result.push_back(c);
					}
				}

				return result;
			}

			/// return syntax error message
			JSON_HEDLEY_RETURNS_NON_NULL
				constexpr const char* get_error_message() const noexcept
			{
				return error_message;
			}

			/////////////////////
			// actual scanner
			/////////////////////

			/*!
			@brief skip the UTF-8 byte order mark
			@return true iff there is no BOM or the correct BOM has been skipped
			*/
			bool skip_bom()
			{
				if (get() == 0xEF)
				{
					// check if we completely parse the BOM
					return get() == 0xBB and get() == 0xBF;
				}

				// the first character is not the beginning of the BOM; unget it to
				// process is later
				unget();
				return true;
			}

			token_type scan()
			{
				// initially, skip the BOM
				if (position.chars_read_total == 0 and not skip_bom())
				{
					error_message = "invalid BOM; must be 0xEF 0xBB 0xBF if given";
					return token_type::parse_error;
				}

				// read next character and ignore whitespace
				do
				{
					get();
				} while (current == ' ' or current == '\t' or current == '\n' or current == '\r');

				switch (current)
				{
					// structural characters
				case '[':
					return token_type::begin_array;
				case ']':
					return token_type::end_array;
				case '{':
					return token_type::begin_object;
				case '}':
					return token_type::end_object;
				case ':':
					return token_type::name_separator;
				case ',':
					return token_type::value_separator;

					// literals
				case 't':
					return scan_literal("true", 4, token_type::literal_true);
				case 'f':
					return scan_literal("false", 5, token_type::literal_false);
				case 'n':
					return scan_literal("null", 4, token_type::literal_null);

					// string
				case '\"':
					return scan_string();

					// number
				case '-':
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					return scan_number();

					// end of input (the null byte is needed when parsing from
					// string literals)
				case '\0':
				case std::char_traits<char>::eof():
					return token_type::end_of_input;

					// error
				default:
					error_message = "invalid literal";
					return token_type::parse_error;
				}
			}

		private:
			/// input adapter
			detail::input_adapter_t ia = nullptr;

			/// the current character
			std::char_traits<char>::int_type current = std::char_traits<char>::eof();

			/// whether the next get() call should just return current
			bool next_unget = false;

			/// the start position of the current token
			position_t position{};

			/// raw input token string (for error messages)
			std::vector<char> token_string{};

			/// buffer for variable-length tokens (numbers, strings)
			string_t token_buffer{};

			/// a description of occurred lexer errors
			const char* error_message = "";

			// number values
			number_integer_t value_integer = 0;
			number_unsigned_t value_unsigned = 0;
			number_float_t value_float = 0;

			/// the decimal point
			const char decimal_point_char = '.';
		};
	}  // namespace detail
}  // namespace nlohmann

// #include <nlohmann/detail/input/parser.hpp>


#include <cassert> // assert
#include <cmath> // isfinite
#include <cstdint> // uint8_t
#include <functional> // function
#include <string> // string
#include <utility> // move
#include <vector> // vector

// #include <nlohmann/detail/exceptions.hpp>

// #include <nlohmann/detail/input/input_adapters.hpp>

// #include <nlohmann/detail/input/json_sax.hpp>

// #include <nlohmann/detail/input/lexer.hpp>

// #include <nlohmann/detail/macro_scope.hpp>

// #include <nlohmann/detail/meta/is_sax.hpp>

// #include <nlohmann/detail/value_t.hpp>


namespace nlohmann
{
	namespace detail
	{
		////////////
		// parser //
		////////////

		/*!
		@brief syntax analysis
		This class implements a recursive decent parser.
		*/
		template<typename BasicJsonType>
		class parser
		{
			using number_integer_t = typename BasicJsonType::number_integer_t;
			using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
			using number_float_t = typename BasicJsonType::number_float_t;
			using string_t = typename BasicJsonType::string_t;
			using lexer_t = lexer<BasicJsonType>;
			using token_type = typename lexer_t::token_type;

		public:
			enum class parse_event_t : uint8_t
			{
				/// the parser read `{` and started to process a JSON object
				object_start,
				/// the parser read `}` and finished processing a JSON object
				object_end,
				/// the parser read `[` and started to process a JSON array
				array_start,
				/// the parser read `]` and finished processing a JSON array
				array_end,
				/// the parser read a key of a value in an object
				key,
				/// the parser finished reading a JSON value
				value
			};

			using parser_callback_t =
				std::function<bool(int depth, parse_event_t event, BasicJsonType & parsed)>;

			/// a parser reading from an input adapter
			explicit parser(detail::input_adapter_t&& adapter,
				const parser_callback_t cb = nullptr,
				const bool allow_exceptions_ = true)
				: callback(cb), m_lexer(std::move(adapter)), allow_exceptions(allow_exceptions_)
			{
				// read first token
				get_token();
			}

			/*!
			@brief public parser interface
			@param[in] strict      whether to expect the last token to be EOF
			@param[in,out] result  parsed JSON value
			@throw parse_error.101 in case of an unexpected token
			@throw parse_error.102 if to_unicode fails or surrogate error
			@throw parse_error.103 if to_unicode fails
			*/
			void parse(const bool strict, BasicJsonType& result)
			{
				if (callback)
				{
					json_sax_dom_callback_parser<BasicJsonType> sdp(result, callback, allow_exceptions);
					sax_parse_internal(&sdp);
					result.assert_invariant();

					// in strict mode, input must be completely read
					if (strict and (get_token() != token_type::end_of_input))
					{
						sdp.parse_error(m_lexer.get_position(),
							m_lexer.get_token_string(),
							parse_error::create(101, m_lexer.get_position(),
								exception_message(token_type::end_of_input, "value")));
					}

					// in case of an error, return discarded value
					if (sdp.is_errored())
					{
						result = value_t::discarded;
						return;
					}

					// set top-level value to null if it was discarded by the callback
					// function
					if (result.is_discarded())
					{
						result = nullptr;
					}
				}
				else
				{
					json_sax_dom_parser<BasicJsonType> sdp(result, allow_exceptions);
					sax_parse_internal(&sdp);
					result.assert_invariant();

					// in strict mode, input must be completely read
					if (strict and (get_token() != token_type::end_of_input))
					{
						sdp.parse_error(m_lexer.get_position(),
							m_lexer.get_token_string(),
							parse_error::create(101, m_lexer.get_position(),
								exception_message(token_type::end_of_input, "value")));
					}

					// in case of an error, return discarded value
					if (sdp.is_errored())
					{
						result = value_t::discarded;
						return;
					}
				}
			}

			/*!
			@brief public accept interface
			@param[in] strict  whether to expect the last token to be EOF
			@return whether the input is a proper JSON text
			*/
			bool accept(const bool strict = true)
			{
				json_sax_acceptor<BasicJsonType> sax_acceptor;
				return sax_parse(&sax_acceptor, strict);
			}

			template <typename SAX>
			JSON_HEDLEY_NON_NULL(2)
				bool sax_parse(SAX* sax, const bool strict = true)
			{
				(void)detail::is_sax_static_asserts<SAX, BasicJsonType> {};
				const bool result = sax_parse_internal(sax);

				// strict mode: next byte must be EOF
				if (result and strict and (get_token() != token_type::end_of_input))
				{
					return sax->parse_error(m_lexer.get_position(),
						m_lexer.get_token_string(),
						parse_error::create(101, m_lexer.get_position(),
							exception_message(token_type::end_of_input, "value")));
				}

				return result;
			}

		private:
			template <typename SAX>
			JSON_HEDLEY_NON_NULL(2)
				bool sax_parse_internal(SAX* sax)
			{
				// stack to remember the hierarchy of structured values we are parsing
				// true = array; false = object
				std::vector<bool> states;
				// value to avoid a goto (see comment where set to true)
				bool skip_to_state_evaluation = false;

				while (true)
				{
					if (not skip_to_state_evaluation)
					{
						// invariant: get_token() was called before each iteration
						switch (last_token)
						{
						case token_type::begin_object:
						{
							if (JSON_HEDLEY_UNLIKELY(not sax->start_object(std::size_t(-1))))
							{
								return false;
							}

							// closing } -> we are done
							if (get_token() == token_type::end_object)
							{
								if (JSON_HEDLEY_UNLIKELY(not sax->end_object()))
								{
									return false;
								}
								break;
							}

							// parse key
							if (JSON_HEDLEY_UNLIKELY(last_token != token_type::value_string))
							{
								return sax->parse_error(m_lexer.get_position(),
									m_lexer.get_token_string(),
									parse_error::create(101, m_lexer.get_position(),
										exception_message(token_type::value_string, "object key")));
							}
							if (JSON_HEDLEY_UNLIKELY(not sax->key(m_lexer.get_string())))
							{
								return false;
							}

							// parse separator (:)
							if (JSON_HEDLEY_UNLIKELY(get_token() != token_type::name_separator))
							{
								return sax->parse_error(m_lexer.get_position(),
									m_lexer.get_token_string(),
									parse_error::create(101, m_lexer.get_position(),
										exception_message(token_type::name_separator, "object separator")));
							}

							// remember we are now inside an object
							states.push_back(false);

							// parse values
							get_token();
							continue;
						}

						case token_type::begin_array:
						{
							if (JSON_HEDLEY_UNLIKELY(not sax->start_array(std::size_t(-1))))
							{
								return false;
							}

							// closing ] -> we are done
							if (get_token() == token_type::end_array)
							{
								if (JSON_HEDLEY_UNLIKELY(not sax->end_array()))
								{
									return false;
								}
								break;
							}

							// remember we are now inside an array
							states.push_back(true);

							// parse values (no need to call get_token)
							continue;
						}

						case token_type::value_float:
						{
							const auto res = m_lexer.get_number_float();

							if (JSON_HEDLEY_UNLIKELY(not std::isfinite(res)))
							{
								return sax->parse_error(m_lexer.get_position(),
									m_lexer.get_token_string(),
									out_of_range::create(406, "number overflow parsing '" + m_lexer.get_token_string() + "'"));
							}

							if (JSON_HEDLEY_UNLIKELY(not sax->number_float(res, m_lexer.get_string())))
							{
								return false;
							}

							break;
						}

						case token_type::literal_false:
						{
							if (JSON_HEDLEY_UNLIKELY(not sax->boolean(false)))
							{
								return false;
							}
							break;
						}

						case token_type::literal_null:
						{
							if (JSON_HEDLEY_UNLIKELY(not sax->null()))
							{
								return false;
							}
							break;
						}

						case token_type::literal_true:
						{
							if (JSON_HEDLEY_UNLIKELY(not sax->boolean(true)))
							{
								return false;
							}
							break;
						}

						case token_type::value_integer:
						{
							if (JSON_HEDLEY_UNLIKELY(not sax->number_integer(m_lexer.get_number_integer())))
							{
								return false;
							}
							break;
						}

						case token_type::value_string:
						{
							if (JSON_HEDLEY_UNLIKELY(not sax->string(m_lexer.get_string())))
							{
								return false;
							}
							break;
						}

						case token_type::value_unsigned:
						{
							if (JSON_HEDLEY_UNLIKELY(not sax->number_unsigned(m_lexer.get_number_unsigned())))
							{
								return false;
							}
							break;
						}

						case token_type::parse_error:
						{
							// using "uninitialized" to avoid "expected" message
							return sax->parse_error(m_lexer.get_position(),
								m_lexer.get_token_string(),
								parse_error::create(101, m_lexer.get_position(),
									exception_message(token_type::uninitialized, "value")));
						}

						default: // the last token was unexpected
						{
							return sax->parse_error(m_lexer.get_position(),
								m_lexer.get_token_string(),
								parse_error::create(101, m_lexer.get_position(),
									exception_message(token_type::literal_or_value, "value")));
						}
						}
					}
					else
					{
						skip_to_state_evaluation = false;
					}

					// we reached this line after we successfully parsed a value
					if (states.empty())
					{
						// empty stack: we reached the end of the hierarchy: done
						return true;
					}

					if (states.back())  // array
					{
						// comma -> next value
						if (get_token() == token_type::value_separator)
						{
							// parse a new value
							get_token();
							continue;
						}

						// closing ]
						if (JSON_HEDLEY_LIKELY(last_token == token_type::end_array))
						{
							if (JSON_HEDLEY_UNLIKELY(not sax->end_array()))
							{
								return false;
							}

							// We are done with this array. Before we can parse a
							// new value, we need to evaluate the new state first.
							// By setting skip_to_state_evaluation to false, we
							// are effectively jumping to the beginning of this if.
							assert(not states.empty());
							states.pop_back();
							skip_to_state_evaluation = true;
							continue;
						}

						return sax->parse_error(m_lexer.get_position(),
							m_lexer.get_token_string(),
							parse_error::create(101, m_lexer.get_position(),
								exception_message(token_type::end_array, "array")));
					}
					else  // object
					{
						// comma -> next value
						if (get_token() == token_type::value_separator)
						{
							// parse key
							if (JSON_HEDLEY_UNLIKELY(get_token() != token_type::value_string))
							{
								return sax->parse_error(m_lexer.get_position(),
									m_lexer.get_token_string(),
									parse_error::create(101, m_lexer.get_position(),
										exception_message(token_type::value_string, "object key")));
							}

							if (JSON_HEDLEY_UNLIKELY(not sax->key(m_lexer.get_string())))
							{
								return false;
							}

							// parse separator (:)
							if (JSON_HEDLEY_UNLIKELY(get_token() != token_type::name_separator))
							{
								return sax->parse_error(m_lexer.get_position(),
									m_lexer.get_token_string(),
									parse_error::create(101, m_lexer.get_position(),
										exception_message(token_type::name_separator, "object separator")));
							}

							// parse values
							get_token();
							continue;
						}

						// closing }
						if (JSON_HEDLEY_LIKELY(last_token == token_type::end_object))
						{
							if (JSON_HEDLEY_UNLIKELY(not sax->end_object()))
							{
								return false;
							}

							// We are done with this object. Before we can parse a
							// new value, we need to evaluate the new state first.
							// By setting skip_to_state_evaluation to false, we
							// are effectively jumping to the beginning of this if.
							assert(not states.empty());
							states.pop_back();
							skip_to_state_evaluation = true;
							continue;
						}

						return sax->parse_error(m_lexer.get_position(),
							m_lexer.get_token_string(),
							parse_error::create(101, m_lexer.get_position(),
								exception_message(token_type::end_object, "object")));
					}
				}
			}

			/// get next token from lexer
			token_type get_token()
			{
				return last_token = m_lexer.scan();
			}

			std::string exception_message(const token_type expected, const std::string& context)
			{
				std::string error_msg = "syntax error ";

				if (not context.empty())
				{
					error_msg += "while parsing " + context + " ";
				}

				error_msg += "- ";

				if (last_token == token_type::parse_error)
				{
					error_msg += std::string(m_lexer.get_error_message()) + "; last read: '" +
						m_lexer.get_token_string() + "'";
				}
				else
				{
					error_msg += "unexpected " + std::string(lexer_t::token_type_name(last_token));
				}

				if (expected != token_type::uninitialized)
				{
					error_msg += "; expected " + std::string(lexer_t::token_type_name(expected));
				}

				return error_msg;
			}

		private:
			/// callback function
			const parser_callback_t callback = nullptr;
			/// the type of the last read token
			token_type last_token = token_type::uninitialized;
			/// the lexer
			lexer_t m_lexer;
			/// whether to throw exceptions in case of errors
			const bool allow_exceptions = true;
		};
	}  // namespace detail
}  // namespace nlohmann

// #include <nlohmann/detail/iterators/internal_iterator.hpp>


// #include <nlohmann/detail/iterators/primitive_iterator.hpp>


#include <cstddef> // ptrdiff_t
#include <limits>  // numeric_limits

namespace nlohmann
{
	namespace detail
	{
		/*
		@brief an iterator for primitive JSON types
		This class models an iterator for primitive JSON types (boolean, number,
		string). It's only purpose is to allow the iterator/const_iterator classes
		to "iterate" over primitive values. Internally, the iterator is modeled by
		a `difference_type` variable. Value begin_value (`0`) models the begin,
		end_value (`1`) models past the end.
		*/
		class primitive_iterator_t
		{
		private:
			using difference_type = std::ptrdiff_t;
			static constexpr difference_type begin_value = 0;
			static constexpr difference_type end_value = begin_value + 1;

			/// iterator as signed integer type
			difference_type m_it = (std::numeric_limits<std::ptrdiff_t>::min)();

		public:
			constexpr difference_type get_value() const noexcept
			{
				return m_it;
			}

			/// set iterator to a defined beginning
			void set_begin() noexcept
			{
				m_it = begin_value;
			}

			/// set iterator to a defined past the end
			void set_end() noexcept
			{
				m_it = end_value;
			}

			/// return whether the iterator can be dereferenced
			constexpr bool is_begin() const noexcept
			{
				return m_it == begin_value;
			}

			/// return whether the iterator is at end
			constexpr bool is_end() const noexcept
			{
				return m_it == end_value;
			}

			friend constexpr bool operator==(primitive_iterator_t lhs, primitive_iterator_t rhs) noexcept
			{
				return lhs.m_it == rhs.m_it;
			}

			friend constexpr bool operator<(primitive_iterator_t lhs, primitive_iterator_t rhs) noexcept
			{
				return lhs.m_it < rhs.m_it;
			}

			primitive_iterator_t operator+(difference_type n) noexcept
			{
				auto result = *this;
				result += n;
				return result;
			}

			friend constexpr difference_type operator-(primitive_iterator_t lhs, primitive_iterator_t rhs) noexcept
			{
				return lhs.m_it - rhs.m_it;
			}

			primitive_iterator_t& operator++() noexcept
			{
				++m_it;
				return *this;
			}

			primitive_iterator_t const operator++(int) noexcept
			{
				auto result = *this;
				++m_it;
				return result;
			}

			primitive_iterator_t& operator--() noexcept
			{
				--m_it;
				return *this;
			}

			primitive_iterator_t const operator--(int) noexcept
			{
				auto result = *this;
				--m_it;
				return result;
			}

			primitive_iterator_t& operator+=(difference_type n) noexcept
			{
				m_it += n;
				return *this;
			}

			primitive_iterator_t& operator-=(difference_type n) noexcept
			{
				m_it -= n;
				return *this;
			}
		};
	}  // namespace detail
}  // namespace nlohmann


namespace nlohmann
{
	namespace detail
	{
		/*!
		@brief an iterator value
		@note This structure could easily be a union, but MSVC currently does not allow
		unions members with complex constructors, see https://github.com/nlohmann/json/pull/105.
		*/
		template<typename BasicJsonType> struct internal_iterator
		{
			/// iterator for JSON objects
			typename BasicJsonType::object_t::iterator object_iterator{};
			/// iterator for JSON arrays
			typename BasicJsonType::array_t::iterator array_iterator{};
			/// generic iterator for all other types
			primitive_iterator_t primitive_iterator{};
		};
	}  // namespace detail
}  // namespace nlohmann

// #include <nlohmann/detail/iterators/iter_impl.hpp>


#include <ciso646> // not
#include <iterator> // iterator, random_access_iterator_tag, bidirectional_iterator_tag, advance, next
#include <type_traits> // conditional, is_const, remove_const

// #include <nlohmann/detail/exceptions.hpp>

// #include <nlohmann/detail/iterators/internal_iterator.hpp>

// #include <nlohmann/detail/iterators/primitive_iterator.hpp>

// #include <nlohmann/detail/macro_scope.hpp>

// #include <nlohmann/detail/meta/cpp_future.hpp>

// #include <nlohmann/detail/meta/type_traits.hpp>

// #include <nlohmann/detail/value_t.hpp>


namespace nlohmann
{
	namespace detail
	{
		// forward declare, to be able to friend it later on
		template<typename IteratorType> class iteration_proxy;
		template<typename IteratorType> class iteration_proxy_value;

		/*!
		@brief a template for a bidirectional iterator for the @ref basic_json class
		This class implements a both iterators (iterator and const_iterator) for the
		@ref basic_json class.
		@note An iterator is called *initialized* when a pointer to a JSON value has
			  been set (e.g., by a constructor or a copy assignment). If the iterator is
			  default-constructed, it is *uninitialized* and most methods are undefined.
			  **The library uses assertions to detect calls on uninitialized iterators.**
		@requirement The class satisfies the following concept requirements:
		-
		[BidirectionalIterator](https://en.cppreference.com/w/cpp/named_req/BidirectionalIterator):
		  The iterator that can be moved can be moved in both directions (i.e.
		  incremented and decremented).
		@since version 1.0.0, simplified in version 2.0.9, change to bidirectional
			   iterators in version 3.0.0 (see https://github.com/nlohmann/json/issues/593)
		*/
		template<typename BasicJsonType>
		class iter_impl
		{
			/// allow basic_json to access private members
			friend iter_impl<typename std::conditional<std::is_const<BasicJsonType>::value, typename std::remove_const<BasicJsonType>::type, const BasicJsonType>::type>;
			friend BasicJsonType;
			friend iteration_proxy<iter_impl>;
			friend iteration_proxy_value<iter_impl>;

			using object_t = typename BasicJsonType::object_t;
			using array_t = typename BasicJsonType::array_t;
			// make sure BasicJsonType is basic_json or const basic_json
			static_assert(is_basic_json<typename std::remove_const<BasicJsonType>::type>::value,
				"iter_impl only accepts (const) basic_json");

		public:

			/// The std::iterator class template (used as a base class to provide typedefs) is deprecated in C++17.
			/// The C++ Standard has never required user-defined iterators to derive from std::iterator.
			/// A user-defined iterator should provide publicly accessible typedefs named
			/// iterator_category, value_type, difference_type, pointer, and reference.
			/// Note that value_type is required to be non-const, even for constant iterators.
			using iterator_category = std::bidirectional_iterator_tag;

			/// the type of the values when the iterator is dereferenced
			using value_type = typename BasicJsonType::value_type;
			/// a type to represent differences between iterators
			using difference_type = typename BasicJsonType::difference_type;
			/// defines a pointer to the type iterated over (value_type)
			using pointer = typename std::conditional<std::is_const<BasicJsonType>::value,
				typename BasicJsonType::const_pointer,
				typename BasicJsonType::pointer>::type;
			/// defines a reference to the type iterated over (value_type)
			using reference =
				typename std::conditional<std::is_const<BasicJsonType>::value,
				typename BasicJsonType::const_reference,
				typename BasicJsonType::reference>::type;

			/// default constructor
			iter_impl() = default;

			/*!
			@brief constructor for a given JSON instance
			@param[in] object  pointer to a JSON object for this iterator
			@pre object != nullptr
			@post The iterator is initialized; i.e. `m_object != nullptr`.
			*/
			explicit iter_impl(pointer object) noexcept : m_object(object)
			{
				assert(m_object != nullptr);

				switch (m_object->m_type)
				{
				case value_t::object:
				{
					m_it.object_iterator = typename object_t::iterator();
					break;
				}

				case value_t::array:
				{
					m_it.array_iterator = typename array_t::iterator();
					break;
				}

				default:
				{
					m_it.primitive_iterator = primitive_iterator_t();
					break;
				}
				}
			}

			/*!
			@note The conventional copy constructor and copy assignment are implicitly
				  defined. Combined with the following converting constructor and
				  assignment, they support: (1) copy from iterator to iterator, (2)
				  copy from const iterator to const iterator, and (3) conversion from
				  iterator to const iterator. However conversion from const iterator
				  to iterator is not defined.
			*/

			/*!
			@brief const copy constructor
			@param[in] other const iterator to copy from
			@note This copy constuctor had to be defined explicitely to circumvent a bug
				  occuring on msvc v19.0 compiler (VS 2015) debug build. For more
				  information refer to: https://github.com/nlohmann/json/issues/1608
			*/
			iter_impl(const iter_impl<const BasicJsonType>& other) noexcept
				: m_object(other.m_object), m_it(other.m_it)
			{}

			/*!
			@brief converting assignment
			@param[in] other const iterator to copy from
			@return const/non-const iterator
			@note It is not checked whether @a other is initialized.
			*/
			iter_impl& operator=(const iter_impl<const BasicJsonType>& other) noexcept
			{
				m_object = other.m_object;
				m_it = other.m_it;
				return *this;
			}

			/*!
			@brief converting constructor
			@param[in] other  non-const iterator to copy from
			@note It is not checked whether @a other is initialized.
			*/
			iter_impl(const iter_impl<typename std::remove_const<BasicJsonType>::type>& other) noexcept
				: m_object(other.m_object), m_it(other.m_it)
			{}

			/*!
			@brief converting assignment
			@param[in] other  non-const iterator to copy from
			@return const/non-const iterator
			@note It is not checked whether @a other is initialized.
			*/
			iter_impl& operator=(const iter_impl<typename std::remove_const<BasicJsonType>::type>& other) noexcept
			{
				m_object = other.m_object;
				m_it = other.m_it;
				return *this;
			}

		private:
			/*!
			@brief set the iterator to the first value
			@pre The iterator is initialized; i.e. `m_object != nullptr`.
			*/
			void set_begin() noexcept
			{
				assert(m_object != nullptr);

				switch (m_object->m_type)
				{
				case value_t::object:
				{
					m_it.object_iterator = m_object->m_value.object->begin();
					break;
				}

				case value_t::array:
				{
					m_it.array_iterator = m_object->m_value.array->begin();
					break;
				}

				case value_t::null:
				{
					// set to end so begin()==end() is true: null is empty
					m_it.primitive_iterator.set_end();
					break;
				}

				default:
				{
					m_it.primitive_iterator.set_begin();
					break;
				}
				}
			}

			/*!
			@brief set the iterator past the last value
			@pre The iterator is initialized; i.e. `m_object != nullptr`.
			*/
			void set_end() noexcept
			{
				assert(m_object != nullptr);

				switch (m_object->m_type)
				{
				case value_t::object:
				{
					m_it.object_iterator = m_object->m_value.object->end();
					break;
				}

				case value_t::array:
				{
					m_it.array_iterator = m_object->m_value.array->end();
					break;
				}

				default:
				{
					m_it.primitive_iterator.set_end();
					break;
				}
				}
			}

		public:
			/*!
			@brief return a reference to the value pointed to by the iterator
			@pre The iterator is initialized; i.e. `m_object != nullptr`.
			*/
			reference operator*() const
			{
				assert(m_object != nullptr);

				switch (m_object->m_type)
				{
				case value_t::object:
				{
					assert(m_it.object_iterator != m_object->m_value.object->end());
					return m_it.object_iterator->second;
				}

				case value_t::array:
				{
					assert(m_it.array_iterator != m_object->m_value.array->end());
					return *m_it.array_iterator;
				}

				case value_t::null:
					JSON_THROW(invalid_iterator::create(214, "cannot get value"));

				default:
				{
					if (JSON_HEDLEY_LIKELY(m_it.primitive_iterator.is_begin()))
					{
						return *m_object;
					}

					JSON_THROW(invalid_iterator::create(214, "cannot get value"));
				}
				}
			}

			/*!
			@brief dereference the iterator
			@pre The iterator is initialized; i.e. `m_object != nullptr`.
			*/
			pointer operator->() const
			{
				assert(m_object != nullptr);

				switch (m_object->m_type)
				{
				case value_t::object:
				{
					assert(m_it.object_iterator != m_object->m_value.object->end());
					return &(m_it.object_iterator->second);
				}

				case value_t::array:
				{
					assert(m_it.array_iterator != m_object->m_value.array->end());
					return &*m_it.array_iterator;
				}

				default:
				{
					if (JSON_HEDLEY_LIKELY(m_it.primitive_iterator.is_begin()))
					{
						return m_object;
					}

					JSON_THROW(invalid_iterator::create(214, "cannot get value"));
				}
				}
			}

			/*!
			@brief post-increment (it++)
			@pre The iterator is initialized; i.e. `m_object != nullptr`.
			*/
			iter_impl const operator++(int)
			{
				auto result = *this;
				++(*this);
				return result;
			}

			/*!
			@brief pre-increment (++it)
			@pre The iterator is initialized; i.e. `m_object != nullptr`.
			*/
			iter_impl& operator++()
			{
				assert(m_object != nullptr);

				switch (m_object->m_type)
				{
				case value_t::object:
				{
					std::advance(m_it.object_iterator, 1);
					break;
				}

				case value_t::array:
				{
					std::advance(m_it.array_iterator, 1);
					break;
				}

				default:
				{
					++m_it.primitive_iterator;
					break;
				}
				}

				return *this;
			}

			/*!
			@brief post-decrement (it--)
			@pre The iterator is initialized; i.e. `m_object != nullptr`.
			*/
			iter_impl const operator--(int)
			{
				auto result = *this;
				--(*this);
				return result;
			}

			/*!
			@brief pre-decrement (--it)
			@pre The iterator is initialized; i.e. `m_object != nullptr`.
			*/
			iter_impl& operator--()
			{
				assert(m_object != nullptr);

				switch (m_object->m_type)
				{
				case value_t::object:
				{
					std::advance(m_it.object_iterator, -1);
					break;
				}

				case value_t::array:
				{
					std::advance(m_it.array_iterator, -1);
					break;
				}

				default:
				{
					--m_it.primitive_iterator;
					break;
				}
				}

				return *this;
			}

			/*!
			@brief  comparison: equal
			@pre The iterator is initialized; i.e. `m_object != nullptr`.
			*/
			bool operator==(const iter_impl& other) const
			{
				// if objects are not the same, the comparison is undefined
				if (JSON_HEDLEY_UNLIKELY(m_object != other.m_object))
				{
					JSON_THROW(invalid_iterator::create(212, "cannot compare iterators of different containers"));
				}

				assert(m_object != nullptr);

				switch (m_object->m_type)
				{
				case value_t::object:
					return (m_it.object_iterator == other.m_it.object_iterator);

				case value_t::array:
					return (m_it.array_iterator == other.m_it.array_iterator);

				default:
					return (m_it.primitive_iterator == other.m_it.primitive_iterator);
				}
			}

			/*!
			@brief  comparison: not equal
			@pre The iterator is initialized; i.e. `m_object != nullptr`.
			*/
			bool operator!=(const iter_impl& other) const
			{
				return not operator==(other);
			}

			/*!
			@brief  comparison: smaller
			@pre The iterator is initialized; i.e. `m_object != nullptr`.
			*/
			bool operator<(const iter_impl& other) const
			{
				// if objects are not the same, the comparison is undefined
				if (JSON_HEDLEY_UNLIKELY(m_object != other.m_object))
				{
					JSON_THROW(invalid_iterator::create(212, "cannot compare iterators of different containers"));
				}

				assert(m_object != nullptr);

				switch (m_object->m_type)
				{
				case value_t::object:
					JSON_THROW(invalid_iterator::create(213, "cannot compare order of object iterators"));

				case value_t::array:
					return (m_it.array_iterator < other.m_it.array_iterator);

				default:
					return (m_it.primitive_iterator < other.m_it.primitive_iterator);
				}
			}

			/*!
			@brief  comparison: less than or equal
			@pre The iterator is initialized; i.e. `m_object != nullptr`.
			*/
			bool operator<=(const iter_impl& other) const
			{
				return not other.operator < (*this);
			}

			/*!
			@brief  comparison: greater than
			@pre The iterator is initialized; i.e. `m_object != nullptr`.
			*/
			bool operator>(const iter_impl& other) const
			{
				return not operator<=(other);
			}

			/*!
			@brief  comparison: greater than or equal
			@pre The iterator is initialized; i.e. `m_object != nullptr`.
			*/
			bool operator>=(const iter_impl& other) const
			{
				return not operator<(other);
			}

			/*!
			@brief  add to iterator
			@pre The iterator is initialized; i.e. `m_object != nullptr`.
			*/
			iter_impl& operator+=(difference_type i)
			{
				assert(m_object != nullptr);

				switch (m_object->m_type)
				{
				case value_t::object:
					JSON_THROW(invalid_iterator::create(209, "cannot use offsets with object iterators"));

				case value_t::array:
				{
					std::advance(m_it.array_iterator, i);
					break;
				}

				default:
				{
					m_it.primitive_iterator += i;
					break;
				}
				}

				return *this;
			}

			/*!
			@brief  subtract from iterator
			@pre The iterator is initialized; i.e. `m_object != nullptr`.
			*/
			iter_impl& operator-=(difference_type i)
			{
				return operator+=(-i);
			}

			/*!
			@brief  add to iterator
			@pre The iterator is initialized; i.e. `m_object != nullptr`.
			*/
			iter_impl operator+(difference_type i) const
			{
				auto result = *this;
				result += i;
				return result;
			}

			/*!
			@brief  addition of distance and iterator
			@pre The iterator is initialized; i.e. `m_object != nullptr`.
			*/
			friend iter_impl operator+(difference_type i, const iter_impl& it)
			{
				auto result = it;
				result += i;
				return result;
			}

			/*!
			@brief  subtract from iterator
			@pre The iterator is initialized; i.e. `m_object != nullptr`.
			*/
			iter_impl operator-(difference_type i) const
			{
				auto result = *this;
				result -= i;
				return result;
			}

			/*!
			@brief  return difference
			@pre The iterator is initialized; i.e. `m_object != nullptr`.
			*/
			difference_type operator-(const iter_impl& other) const
			{
				assert(m_object != nullptr);

				switch (m_object->m_type)
				{
				case value_t::object:
					JSON_THROW(invalid_iterator::create(209, "cannot use offsets with object iterators"));

				case value_t::array:
					return m_it.array_iterator - other.m_it.array_iterator;

				default:
					return m_it.primitive_iterator - other.m_it.primitive_iterator;
				}
			}

			/*!
			@brief  access to successor
			@pre The iterator is initialized; i.e. `m_object != nullptr`.
			*/
			reference operator[](difference_type n) const
			{
				assert(m_object != nullptr);

				switch (m_object->m_type)
				{
				case value_t::object:
					JSON_THROW(invalid_iterator::create(208, "cannot use operator[] for object iterators"));

				case value_t::array:
					return *std::next(m_it.array_iterator, n);

				case value_t::null:
					JSON_THROW(invalid_iterator::create(214, "cannot get value"));

				default:
				{
					if (JSON_HEDLEY_LIKELY(m_it.primitive_iterator.get_value() == -n))
					{
						return *m_object;
					}

					JSON_THROW(invalid_iterator::create(214, "cannot get value"));
				}
				}
			}

			/*!
			@brief  return the key of an object iterator
			@pre The iterator is initialized; i.e. `m_object != nullptr`.
			*/
			const typename object_t::key_type& key() const
			{
				assert(m_object != nullptr);

				if (JSON_HEDLEY_LIKELY(m_object->is_object()))
				{
					return m_it.object_iterator->first;
				}

				JSON_THROW(invalid_iterator::create(207, "cannot use key() for non-object iterators"));
			}

			/*!
			@brief  return the value of an iterator
			@pre The iterator is initialized; i.e. `m_object != nullptr`.
			*/
			reference value() const
			{
				return operator*();
			}

		private:
			/// associated JSON instance
			pointer m_object = nullptr;
			/// the actual iterator of the associated instance
			internal_iterator<typename std::remove_const<BasicJsonType>::type> m_it{};
		};
	} // namespace detail
} // namespace nlohmann

// #include <nlohmann/detail/iterators/iteration_proxy.hpp>

// #include <nlohmann/detail/iterators/json_reverse_iterator.hpp>


#include <cstddef> // ptrdiff_t
#include <iterator> // reverse_iterator
#include <utility> // declval

namespace nlohmann
{
	namespace detail
	{
		//////////////////////
		// reverse_iterator //
		//////////////////////

		/*!
		@brief a template for a reverse iterator class
		@tparam Base the base iterator type to reverse. Valid types are @ref
		iterator (to create @ref reverse_iterator) and @ref const_iterator (to
		create @ref const_reverse_iterator).
		@requirement The class satisfies the following concept requirements:
		-
		[BidirectionalIterator](https://en.cppreference.com/w/cpp/named_req/BidirectionalIterator):
		  The iterator that can be moved can be moved in both directions (i.e.
		  incremented and decremented).
		- [OutputIterator](https://en.cppreference.com/w/cpp/named_req/OutputIterator):
		  It is possible to write to the pointed-to element (only if @a Base is
		  @ref iterator).
		@since version 1.0.0
		*/
		template<typename Base>
		class json_reverse_iterator : public std::reverse_iterator<Base>
		{
		public:
			using difference_type = std::ptrdiff_t;
			/// shortcut to the reverse iterator adapter
			using base_iterator = std::reverse_iterator<Base>;
			/// the reference type for the pointed-to element
			using reference = typename Base::reference;

			/// create reverse iterator from iterator
			explicit json_reverse_iterator(const typename base_iterator::iterator_type& it) noexcept
				: base_iterator(it) {}

			/// create reverse iterator from base class
			explicit json_reverse_iterator(const base_iterator& it) noexcept : base_iterator(it) {}

			/// post-increment (it++)
			json_reverse_iterator const operator++(int)
			{
				return static_cast<json_reverse_iterator>(base_iterator::operator++(1));
			}

			/// pre-increment (++it)
			json_reverse_iterator& operator++()
			{
				return static_cast<json_reverse_iterator&>(base_iterator::operator++());
			}

			/// post-decrement (it--)
			json_reverse_iterator const operator--(int)
			{
				return static_cast<json_reverse_iterator>(base_iterator::operator--(1));
			}

			/// pre-decrement (--it)
			json_reverse_iterator& operator--()
			{
				return static_cast<json_reverse_iterator&>(base_iterator::operator--());
			}

			/// add to iterator
			json_reverse_iterator& operator+=(difference_type i)
			{
				return static_cast<json_reverse_iterator&>(base_iterator::operator+=(i));
			}

			/// add to iterator
			json_reverse_iterator operator+(difference_type i) const
			{
				return static_cast<json_reverse_iterator>(base_iterator::operator+(i));
			}

			/// subtract from iterator
			json_reverse_iterator operator-(difference_type i) const
			{
				return static_cast<json_reverse_iterator>(base_iterator::operator-(i));
			}

			/// return difference
			difference_type operator-(const json_reverse_iterator& other) const
			{
				return base_iterator(*this) - base_iterator(other);
			}

			/// access to successor
			reference operator[](difference_type n) const
			{
				return *(this->operator+(n));
			}

			/// return the key of an object iterator
			auto key() const -> decltype(std::declval<Base>().key())
			{
				auto it = --this->base();
				return it.key();
			}

			/// return the value of an iterator
			reference value() const
			{
				auto it = --this->base();
				return it.operator * ();
			}
		};
	}  // namespace detail
}  // namespace nlohmann

// #include <nlohmann/detail/iterators/primitive_iterator.hpp>

// #include <nlohmann/detail/json_pointer.hpp>


#include <algorithm> // all_of
#include <cassert> // assert
#include <cctype> // isdigit
#include <numeric> // accumulate
#include <string> // string
#include <utility> // move
#include <vector> // vector

// #include <nlohmann/detail/exceptions.hpp>

// #include <nlohmann/detail/macro_scope.hpp>

// #include <nlohmann/detail/value_t.hpp>


namespace nlohmann
{
	template<typename BasicJsonType>
	class json_pointer
	{
		// allow basic_json to access private members
		NLOHMANN_BASIC_JSON_TPL_DECLARATION
			friend class basic_json;

	public:
		/*!
		@brief create JSON pointer
		Create a JSON pointer according to the syntax described in
		[Section 3 of RFC6901](https://tools.ietf.org/html/rfc6901#section-3).
		@param[in] s  string representing the JSON pointer; if omitted, the empty
					  string is assumed which references the whole JSON value
		@throw parse_error.107 if the given JSON pointer @a s is nonempty and does
							   not begin with a slash (`/`); see example below
		@throw parse_error.108 if a tilde (`~`) in the given JSON pointer @a s is
		not followed by `0` (representing `~`) or `1` (representing `/`); see
		example below
		@liveexample{The example shows the construction several valid JSON pointers
		as well as the exceptional behavior.,json_pointer}
		@since version 2.0.0
		*/
		explicit json_pointer(const std::string& s = "")
			: reference_tokens(split(s))
		{}

		/*!
		@brief return a string representation of the JSON pointer
		@invariant For each JSON pointer `ptr`, it holds:
		@code {.cpp}
		ptr == json_pointer(ptr.to_string());
		@endcode
		@return a string representation of the JSON pointer
		@liveexample{The example shows the result of `to_string`.,json_pointer__to_string}
		@since version 2.0.0
		*/
		std::string to_string() const
		{
			return std::accumulate(reference_tokens.begin(), reference_tokens.end(),
				std::string{},
				[](const std::string& a, const std::string& b)
				{
					return a + "/" + escape(b);
				});
		}

		/// @copydoc to_string()
		operator std::string() const
		{
			return to_string();
		}

		/*!
		@brief append another JSON pointer at the end of this JSON pointer
		@param[in] ptr  JSON pointer to append
		@return JSON pointer with @a ptr appended
		@liveexample{The example shows the usage of `operator/=`.,json_pointer__operator_add}
		@complexity Linear in the length of @a ptr.
		@sa @ref operator/=(std::string) to append a reference token
		@sa @ref operator/=(std::size_t) to append an array index
		@sa @ref operator/(const json_pointer&, const json_pointer&) for a binary operator
		@since version 3.6.0
		*/
		json_pointer& operator/=(const json_pointer& ptr)
		{
			reference_tokens.insert(reference_tokens.end(),
				ptr.reference_tokens.begin(),
				ptr.reference_tokens.end());
			return *this;
		}

		/*!
		@brief append an unescaped reference token at the end of this JSON pointer
		@param[in] token  reference token to append
		@return JSON pointer with @a token appended without escaping @a token
		@liveexample{The example shows the usage of `operator/=`.,json_pointer__operator_add}
		@complexity Amortized constant.
		@sa @ref operator/=(const json_pointer&) to append a JSON pointer
		@sa @ref operator/=(std::size_t) to append an array index
		@sa @ref operator/(const json_pointer&, std::size_t) for a binary operator
		@since version 3.6.0
		*/
		json_pointer& operator/=(std::string token)
		{
			push_back(std::move(token));
			return *this;
		}

		/*!
		@brief append an array index at the end of this JSON pointer
		@param[in] array_index  array index ot append
		@return JSON pointer with @a array_index appended
		@liveexample{The example shows the usage of `operator/=`.,json_pointer__operator_add}
		@complexity Amortized constant.
		@sa @ref operator/=(const json_pointer&) to append a JSON pointer
		@sa @ref operator/=(std::string) to append a reference token
		@sa @ref operator/(const json_pointer&, std::string) for a binary operator
		@since version 3.6.0
		*/
		json_pointer& operator/=(std::size_t array_index)
		{
			return *this /= std::to_string(array_index);
		}

		/*!
		@brief create a new JSON pointer by appending the right JSON pointer at the end of the left JSON pointer
		@param[in] lhs  JSON pointer
		@param[in] rhs  JSON pointer
		@return a new JSON pointer with @a rhs appended to @a lhs
		@liveexample{The example shows the usage of `operator/`.,json_pointer__operator_add_binary}
		@complexity Linear in the length of @a lhs and @a rhs.
		@sa @ref operator/=(const json_pointer&) to append a JSON pointer
		@since version 3.6.0
		*/
		friend json_pointer operator/(const json_pointer& lhs,
			const json_pointer& rhs)
		{
			return json_pointer(lhs) /= rhs;
		}

		/*!
		@brief create a new JSON pointer by appending the unescaped token at the end of the JSON pointer
		@param[in] ptr  JSON pointer
		@param[in] token  reference token
		@return a new JSON pointer with unescaped @a token appended to @a ptr
		@liveexample{The example shows the usage of `operator/`.,json_pointer__operator_add_binary}
		@complexity Linear in the length of @a ptr.
		@sa @ref operator/=(std::string) to append a reference token
		@since version 3.6.0
		*/
		friend json_pointer operator/(const json_pointer& ptr, std::string token)
		{
			return json_pointer(ptr) /= std::move(token);
		}

		/*!
		@brief create a new JSON pointer by appending the array-index-token at the end of the JSON pointer
		@param[in] ptr  JSON pointer
		@param[in] array_index  array index
		@return a new JSON pointer with @a array_index appended to @a ptr
		@liveexample{The example shows the usage of `operator/`.,json_pointer__operator_add_binary}
		@complexity Linear in the length of @a ptr.
		@sa @ref operator/=(std::size_t) to append an array index
		@since version 3.6.0
		*/
		friend json_pointer operator/(const json_pointer& ptr, std::size_t array_index)
		{
			return json_pointer(ptr) /= array_index;
		}

		/*!
		@brief returns the parent of this JSON pointer
		@return parent of this JSON pointer; in case this JSON pointer is the root,
				the root itself is returned
		@complexity Linear in the length of the JSON pointer.
		@liveexample{The example shows the result of `parent_pointer` for different
		JSON Pointers.,json_pointer__parent_pointer}
		@since version 3.6.0
		*/
		json_pointer parent_pointer() const
		{
			if (empty())
			{
				return *this;
			}

			json_pointer res = *this;
			res.pop_back();
			return res;
		}

		/*!
		@brief remove last reference token
		@pre not `empty()`
		@liveexample{The example shows the usage of `pop_back`.,json_pointer__pop_back}
		@complexity Constant.
		@throw out_of_range.405 if JSON pointer has no parent
		@since version 3.6.0
		*/
		void pop_back()
		{
			if (JSON_HEDLEY_UNLIKELY(empty()))
			{
				JSON_THROW(detail::out_of_range::create(405, "JSON pointer has no parent"));
			}

			reference_tokens.pop_back();
		}

		/*!
		@brief return last reference token
		@pre not `empty()`
		@return last reference token
		@liveexample{The example shows the usage of `back`.,json_pointer__back}
		@complexity Constant.
		@throw out_of_range.405 if JSON pointer has no parent
		@since version 3.6.0
		*/
		const std::string& back()
		{
			if (JSON_HEDLEY_UNLIKELY(empty()))
			{
				JSON_THROW(detail::out_of_range::create(405, "JSON pointer has no parent"));
			}

			return reference_tokens.back();
		}

		/*!
		@brief append an unescaped token at the end of the reference pointer
		@param[in] token  token to add
		@complexity Amortized constant.
		@liveexample{The example shows the result of `push_back` for different
		JSON Pointers.,json_pointer__push_back}
		@since version 3.6.0
		*/
		void push_back(const std::string& token)
		{
			reference_tokens.push_back(token);
		}

		/// @copydoc push_back(const std::string&)
		void push_back(std::string&& token)
		{
			reference_tokens.push_back(std::move(token));
		}

		/*!
		@brief return whether pointer points to the root document
		@return true iff the JSON pointer points to the root document
		@complexity Constant.
		@exceptionsafety No-throw guarantee: this function never throws exceptions.
		@liveexample{The example shows the result of `empty` for different JSON
		Pointers.,json_pointer__empty}
		@since version 3.6.0
		*/
		bool empty() const noexcept
		{
			return reference_tokens.empty();
		}

	private:
		/*!
		@param[in] s  reference token to be converted into an array index
		@return integer representation of @a s
		@throw out_of_range.404 if string @a s could not be converted to an integer
		*/
		static int array_index(const std::string& s)
		{
			std::size_t processed_chars = 0;
			const int res = std::stoi(s, &processed_chars);

			// check if the string was completely read
			if (JSON_HEDLEY_UNLIKELY(processed_chars != s.size()))
			{
				JSON_THROW(detail::out_of_range::create(404, "unresolved reference token '" + s + "'"));
			}

			return res;
		}

		json_pointer top() const
		{
			if (JSON_HEDLEY_UNLIKELY(empty()))
			{
				JSON_THROW(detail::out_of_range::create(405, "JSON pointer has no parent"));
			}

			json_pointer result = *this;
			result.reference_tokens = { reference_tokens[0] };
			return result;
		}

		/*!
		@brief create and return a reference to the pointed to value
		@complexity Linear in the number of reference tokens.
		@throw parse_error.109 if array index is not a number
		@throw type_error.313 if value cannot be unflattened
		*/
		BasicJsonType& get_and_create(BasicJsonType& j) const
		{
			using size_type = typename BasicJsonType::size_type;
			auto result = &j;

			// in case no reference tokens exist, return a reference to the JSON value
			// j which will be overwritten by a primitive value
			for (const auto& reference_token : reference_tokens)
			{
				switch (result->type())
				{
				case detail::value_t::null:
				{
					if (reference_token == "0")
					{
						// start a new array if reference token is 0
						result = &result->operator[](0);
					}
					else
					{
						// start a new object otherwise
						result = &result->operator[](reference_token);
					}
					break;
				}

				case detail::value_t::object:
				{
					// create an entry in the object
					result = &result->operator[](reference_token);
					break;
				}

				case detail::value_t::array:
				{
					// create an entry in the array
					JSON_TRY
					{
						result = &result->operator[](static_cast<size_type>(array_index(reference_token)));
					}
						JSON_CATCH(std::invalid_argument&)
					{
						JSON_THROW(detail::parse_error::create(109, 0, "array index '" + reference_token + "' is not a number"));
					}
					break;
				}

				/*
				The following code is only reached if there exists a reference
				token _and_ the current value is primitive. In this case, we have
				an error situation, because primitive values may only occur as
				single value; that is, with an empty list of reference tokens.
				*/
				default:
					JSON_THROW(detail::type_error::create(313, "invalid value to unflatten"));
				}
			}

			return *result;
		}

		/*!
		@brief return a reference to the pointed to value
		@note This version does not throw if a value is not present, but tries to
			  create nested values instead. For instance, calling this function
			  with pointer `"/this/that"` on a null value is equivalent to calling
			  `operator[]("this").operator[]("that")` on that value, effectively
			  changing the null value to an object.
		@param[in] ptr  a JSON value
		@return reference to the JSON value pointed to by the JSON pointer
		@complexity Linear in the length of the JSON pointer.
		@throw parse_error.106   if an array index begins with '0'
		@throw parse_error.109   if an array index was not a number
		@throw out_of_range.404  if the JSON pointer can not be resolved
		*/
		BasicJsonType& get_unchecked(BasicJsonType* ptr) const
		{
			using size_type = typename BasicJsonType::size_type;
			for (const auto& reference_token : reference_tokens)
			{
				// convert null values to arrays or objects before continuing
				if (ptr->is_null())
				{
					// check if reference token is a number
					const bool nums =
						std::all_of(reference_token.begin(), reference_token.end(),
							[](const unsigned char x)
							{
								return std::isdigit(x);
							});

					// change value to array for numbers or "-" or to object otherwise
					*ptr = (nums or reference_token == "-")
						? detail::value_t::array
						: detail::value_t::object;
				}

				switch (ptr->type())
				{
				case detail::value_t::object:
				{
					// use unchecked object access
					ptr = &ptr->operator[](reference_token);
					break;
				}

				case detail::value_t::array:
				{
					// error condition (cf. RFC 6901, Sect. 4)
					if (JSON_HEDLEY_UNLIKELY(reference_token.size() > 1 and reference_token[0] == '0'))
					{
						JSON_THROW(detail::parse_error::create(106, 0,
							"array index '" + reference_token +
							"' must not begin with '0'"));
					}

					if (reference_token == "-")
					{
						// explicitly treat "-" as index beyond the end
						ptr = &ptr->operator[](ptr->m_value.array->size());
					}
					else
					{
						// convert array index to number; unchecked access
						JSON_TRY
						{
							ptr = &ptr->operator[](
								static_cast<size_type>(array_index(reference_token)));
						}
							JSON_CATCH(std::invalid_argument&)
						{
							JSON_THROW(detail::parse_error::create(109, 0, "array index '" + reference_token + "' is not a number"));
						}
					}
					break;
				}

				default:
					JSON_THROW(detail::out_of_range::create(404, "unresolved reference token '" + reference_token + "'"));
				}
			}

			return *ptr;
		}

		/*!
		@throw parse_error.106   if an array index begins with '0'
		@throw parse_error.109   if an array index was not a number
		@throw out_of_range.402  if the array index '-' is used
		@throw out_of_range.404  if the JSON pointer can not be resolved
		*/
		BasicJsonType& get_checked(BasicJsonType* ptr) const
		{
			using size_type = typename BasicJsonType::size_type;
			for (const auto& reference_token : reference_tokens)
			{
				switch (ptr->type())
				{
				case detail::value_t::object:
				{
					// note: at performs range check
					ptr = &ptr->at(reference_token);
					break;
				}

				case detail::value_t::array:
				{
					if (JSON_HEDLEY_UNLIKELY(reference_token == "-"))
					{
						// "-" always fails the range check
						JSON_THROW(detail::out_of_range::create(402,
							"array index '-' (" + std::to_string(ptr->m_value.array->size()) +
							") is out of range"));
					}

					// error condition (cf. RFC 6901, Sect. 4)
					if (JSON_HEDLEY_UNLIKELY(reference_token.size() > 1 and reference_token[0] == '0'))
					{
						JSON_THROW(detail::parse_error::create(106, 0,
							"array index '" + reference_token +
							"' must not begin with '0'"));
					}

					// note: at performs range check
					JSON_TRY
					{
						ptr = &ptr->at(static_cast<size_type>(array_index(reference_token)));
					}
						JSON_CATCH(std::invalid_argument&)
					{
						JSON_THROW(detail::parse_error::create(109, 0, "array index '" + reference_token + "' is not a number"));
					}
					break;
				}

				default:
					JSON_THROW(detail::out_of_range::create(404, "unresolved reference token '" + reference_token + "'"));
				}
			}

			return *ptr;
		}

		/*!
		@brief return a const reference to the pointed to value
		@param[in] ptr  a JSON value
		@return const reference to the JSON value pointed to by the JSON
		pointer
		@throw parse_error.106   if an array index begins with '0'
		@throw parse_error.109   if an array index was not a number
		@throw out_of_range.402  if the array index '-' is used
		@throw out_of_range.404  if the JSON pointer can not be resolved
		*/
		const BasicJsonType& get_unchecked(const BasicJsonType* ptr) const
		{
			using size_type = typename BasicJsonType::size_type;
			for (const auto& reference_token : reference_tokens)
			{
				switch (ptr->type())
				{
				case detail::value_t::object:
				{
					// use unchecked object access
					ptr = &ptr->operator[](reference_token);
					break;
				}

				case detail::value_t::array:
				{
					if (JSON_HEDLEY_UNLIKELY(reference_token == "-"))
					{
						// "-" cannot be used for const access
						JSON_THROW(detail::out_of_range::create(402,
							"array index '-' (" + std::to_string(ptr->m_value.array->size()) +
							") is out of range"));
					}

					// error condition (cf. RFC 6901, Sect. 4)
					if (JSON_HEDLEY_UNLIKELY(reference_token.size() > 1 and reference_token[0] == '0'))
					{
						JSON_THROW(detail::parse_error::create(106, 0,
							"array index '" + reference_token +
							"' must not begin with '0'"));
					}

					// use unchecked array access
					JSON_TRY
					{
						ptr = &ptr->operator[](
							static_cast<size_type>(array_index(reference_token)));
					}
						JSON_CATCH(std::invalid_argument&)
					{
						JSON_THROW(detail::parse_error::create(109, 0, "array index '" + reference_token + "' is not a number"));
					}
					break;
				}

				default:
					JSON_THROW(detail::out_of_range::create(404, "unresolved reference token '" + reference_token + "'"));
				}
			}

			return *ptr;
		}

		/*!
		@throw parse_error.106   if an array index begins with '0'
		@throw parse_error.109   if an array index was not a number
		@throw out_of_range.402  if the array index '-' is used
		@throw out_of_range.404  if the JSON pointer can not be resolved
		*/
		const BasicJsonType& get_checked(const BasicJsonType* ptr) const
		{
			using size_type = typename BasicJsonType::size_type;
			for (const auto& reference_token : reference_tokens)
			{
				switch (ptr->type())
				{
				case detail::value_t::object:
				{
					// note: at performs range check
					ptr = &ptr->at(reference_token);
					break;
				}

				case detail::value_t::array:
				{
					if (JSON_HEDLEY_UNLIKELY(reference_token == "-"))
					{
						// "-" always fails the range check
						JSON_THROW(detail::out_of_range::create(402,
							"array index '-' (" + std::to_string(ptr->m_value.array->size()) +
							") is out of range"));
					}

					// error condition (cf. RFC 6901, Sect. 4)
					if (JSON_HEDLEY_UNLIKELY(reference_token.size() > 1 and reference_token[0] == '0'))
					{
						JSON_THROW(detail::parse_error::create(106, 0,
							"array index '" + reference_token +
							"' must not begin with '0'"));
					}

					// note: at performs range check
					JSON_TRY
					{
						ptr = &ptr->at(static_cast<size_type>(array_index(reference_token)));
					}
						JSON_CATCH(std::invalid_argument&)
					{
						JSON_THROW(detail::parse_error::create(109, 0, "array index '" + reference_token + "' is not a number"));
					}
					break;
				}

				default:
					JSON_THROW(detail::out_of_range::create(404, "unresolved reference token '" + reference_token + "'"));
				}
			}

			return *ptr;
		}

		/*!
		@throw parse_error.106   if an array index begins with '0'
		@throw parse_error.109   if an array index was not a number
		*/
		bool contains(const BasicJsonType* ptr) const
		{
			using size_type = typename BasicJsonType::size_type;
			for (const auto& reference_token : reference_tokens)
			{
				switch (ptr->type())
				{
				case detail::value_t::object:
				{
					if (not ptr->contains(reference_token))
					{
						// we did not find the key in the object
						return false;
					}

					ptr = &ptr->operator[](reference_token);
					break;
				}

				case detail::value_t::array:
				{
					if (JSON_HEDLEY_UNLIKELY(reference_token == "-"))
					{
						// "-" always fails the range check
						return false;
					}

					// error condition (cf. RFC 6901, Sect. 4)
					if (JSON_HEDLEY_UNLIKELY(reference_token.size() > 1 and reference_token[0] == '0'))
					{
						JSON_THROW(detail::parse_error::create(106, 0,
							"array index '" + reference_token +
							"' must not begin with '0'"));
					}

					JSON_TRY
					{
						const auto idx = static_cast<size_type>(array_index(reference_token));
						if (idx >= ptr->size())
						{
							// index out of range
							return false;
						}

						ptr = &ptr->operator[](idx);
						break;
					}
						JSON_CATCH(std::invalid_argument&)
					{
						JSON_THROW(detail::parse_error::create(109, 0, "array index '" + reference_token + "' is not a number"));
					}
					break;
				}

				default:
				{
					// we do not expect primitive values if there is still a
					// reference token to process
					return false;
				}
				}
			}

			// no reference token left means we found a primitive value
			return true;
		}

		/*!
		@brief split the string input to reference tokens
		@note This function is only called by the json_pointer constructor.
			  All exceptions below are documented there.
		@throw parse_error.107  if the pointer is not empty or begins with '/'
		@throw parse_error.108  if character '~' is not followed by '0' or '1'
		*/
		static std::vector<std::string> split(const std::string& reference_string)
		{
			std::vector<std::string> result;

			// special case: empty reference string -> no reference tokens
			if (reference_string.empty())
			{
				return result;
			}

			// check if nonempty reference string begins with slash
			if (JSON_HEDLEY_UNLIKELY(reference_string[0] != '/'))
			{
				JSON_THROW(detail::parse_error::create(107, 1,
					"JSON pointer must be empty or begin with '/' - was: '" +
					reference_string + "'"));
			}

			// extract the reference tokens:
			// - slash: position of the last read slash (or end of string)
			// - start: position after the previous slash
			for (
				// search for the first slash after the first character
				std::size_t slash = reference_string.find_first_of('/', 1),
				// set the beginning of the first reference token
				start = 1;
				// we can stop if start == 0 (if slash == std::string::npos)
				start != 0;
				// set the beginning of the next reference token
				// (will eventually be 0 if slash == std::string::npos)
				start = (slash == std::string::npos) ? 0 : slash + 1,
				// find next slash
				slash = reference_string.find_first_of('/', start))
			{
				// use the text between the beginning of the reference token
				// (start) and the last slash (slash).
				auto reference_token = reference_string.substr(start, slash - start);

				// check reference tokens are properly escaped
				for (std::size_t pos = reference_token.find_first_of('~');
					pos != std::string::npos;
					pos = reference_token.find_first_of('~', pos + 1))
				{
					assert(reference_token[pos] == '~');

					// ~ must be followed by 0 or 1
					if (JSON_HEDLEY_UNLIKELY(pos == reference_token.size() - 1 or
						(reference_token[pos + 1] != '0' and
							reference_token[pos + 1] != '1')))
					{
						JSON_THROW(detail::parse_error::create(108, 0, "escape character '~' must be followed with '0' or '1'"));
					}
				}

				// finally, store the reference token
				unescape(reference_token);
				result.push_back(reference_token);
			}

			return result;
		}

		/*!
		@brief replace all occurrences of a substring by another string
		@param[in,out] s  the string to manipulate; changed so that all
					   occurrences of @a f are replaced with @a t
		@param[in]     f  the substring to replace with @a t
		@param[in]     t  the string to replace @a f
		@pre The search string @a f must not be empty. **This precondition is
		enforced with an assertion.**
		@since version 2.0.0
		*/
		static void replace_substring(std::string& s, const std::string& f,
			const std::string& t)
		{
			assert(not f.empty());
			for (auto pos = s.find(f);                // find first occurrence of f
				pos != std::string::npos;         // make sure f was found
				s.replace(pos, f.size(), t),      // replace with t, and
				pos = s.find(f, pos + t.size()))  // find next occurrence of f
			{
			}
		}

		/// escape "~" to "~0" and "/" to "~1"
		static std::string escape(std::string s)
		{
			replace_substring(s, "~", "~0");
			replace_substring(s, "/", "~1");
			return s;
		}

		/// unescape "~1" to tilde and "~0" to slash (order is important!)
		static void unescape(std::string& s)
		{
			replace_substring(s, "~1", "/");
			replace_substring(s, "~0", "~");
		}

		/*!
		@param[in] reference_string  the reference string to the current value
		@param[in] value             the value to consider
		@param[in,out] result        the result object to insert values to
		@note Empty objects or arrays are flattened to `null`.
		*/
		static void flatten(const std::string& reference_string,
			const BasicJsonType& value,
			BasicJsonType& result)
		{
			switch (value.type())
			{
			case detail::value_t::array:
			{
				if (value.m_value.array->empty())
				{
					// flatten empty array as null
					result[reference_string] = nullptr;
				}
				else
				{
					// iterate array and use index as reference string
					for (std::size_t i = 0; i < value.m_value.array->size(); ++i)
					{
						flatten(reference_string + "/" + std::to_string(i),
							value.m_value.array->operator[](i), result);
					}
				}
				break;
			}

			case detail::value_t::object:
			{
				if (value.m_value.object->empty())
				{
					// flatten empty object as null
					result[reference_string] = nullptr;
				}
				else
				{
					// iterate object and use keys as reference string
					for (const auto& element : *value.m_value.object)
					{
						flatten(reference_string + "/" + escape(element.first), element.second, result);
					}
				}
				break;
			}

			default:
			{
				// add primitive value with its reference string
				result[reference_string] = value;
				break;
			}
			}
		}

		/*!
		@param[in] value  flattened JSON
		@return unflattened JSON
		@throw parse_error.109 if array index is not a number
		@throw type_error.314  if value is not an object
		@throw type_error.315  if object values are not primitive
		@throw type_error.313  if value cannot be unflattened
		*/
		static BasicJsonType
			unflatten(const BasicJsonType& value)
		{
			if (JSON_HEDLEY_UNLIKELY(not value.is_object()))
			{
				JSON_THROW(detail::type_error::create(314, "only objects can be unflattened"));
			}

			BasicJsonType result;

			// iterate the JSON object values
			for (const auto& element : *value.m_value.object)
			{
				if (JSON_HEDLEY_UNLIKELY(not element.second.is_primitive()))
				{
					JSON_THROW(detail::type_error::create(315, "values in object must be primitive"));
				}

				// assign value to reference pointed to by JSON pointer; Note that if
				// the JSON pointer is "" (i.e., points to the whole value), function
				// get_and_create returns a reference to result itself. An assignment
				// will then create a primitive value.
				json_pointer(element.first).get_and_create(result) = element.second;
			}

			return result;
		}

		/*!
		@brief compares two JSON pointers for equality
		@param[in] lhs  JSON pointer to compare
		@param[in] rhs  JSON pointer to compare
		@return whether @a lhs is equal to @a rhs
		@complexity Linear in the length of the JSON pointer
		@exceptionsafety No-throw guarantee: this function never throws exceptions.
		*/
		friend bool operator==(json_pointer const& lhs,
			json_pointer const& rhs) noexcept
		{
			return lhs.reference_tokens == rhs.reference_tokens;
		}

		/*!
		@brief compares two JSON pointers for inequality
		@param[in] lhs  JSON pointer to compare
		@param[in] rhs  JSON pointer to compare
		@return whether @a lhs is not equal @a rhs
		@complexity Linear in the length of the JSON pointer
		@exceptionsafety No-throw guarantee: this function never throws exceptions.
		*/
		friend bool operator!=(json_pointer const& lhs,
			json_pointer const& rhs) noexcept
		{
			return not (lhs == rhs);
		}

		/// the reference tokens
		std::vector<std::string> reference_tokens;
	};
}  // namespace nlohmann

// #include <nlohmann/detail/json_ref.hpp>


#include <initializer_list>
#include <utility>

// #include <nlohmann/detail/meta/type_traits.hpp>


namespace nlohmann
{
	namespace detail
	{
		template<typename BasicJsonType>
		class json_ref
		{
		public:
			using value_type = BasicJsonType;

			json_ref(value_type&& value)
				: owned_value(std::move(value)), value_ref(&owned_value), is_rvalue(true)
			{}

			json_ref(const value_type& value)
				: value_ref(const_cast<value_type*>(&value)), is_rvalue(false)
			{}

			json_ref(std::initializer_list<json_ref> init)
				: owned_value(init), value_ref(&owned_value), is_rvalue(true)
			{}

			template <
				class... Args,
				enable_if_t<std::is_constructible<value_type, Args...>::value, int> = 0 >
				json_ref(Args&& ... args)
				: owned_value(std::forward<Args>(args)...), value_ref(&owned_value),
				is_rvalue(true) {}

			// class should be movable only
			json_ref(json_ref&&) = default;
			json_ref(const json_ref&) = delete;
			json_ref& operator=(const json_ref&) = delete;
			json_ref& operator=(json_ref&&) = delete;
			~json_ref() = default;

			value_type moved_or_copied() const
			{
				if (is_rvalue)
				{
					return std::move(*value_ref);
				}
				return *value_ref;
			}

			value_type const& operator*() const
			{
				return *static_cast<value_type const*>(value_ref);
			}

			value_type const* operator->() const
			{
				return static_cast<value_type const*>(value_ref);
			}

		private:
			mutable value_type owned_value = nullptr;
			value_type* value_ref = nullptr;
			const bool is_rvalue;
		};
	}  // namespace detail
}  // namespace nlohmann

// #include <nlohmann/detail/macro_scope.hpp>

// #include <nlohmann/detail/meta/cpp_future.hpp>

// #include <nlohmann/detail/meta/type_traits.hpp>

// #include <nlohmann/detail/output/binary_writer.hpp>


#include <algorithm> // reverse
#include <array> // array
#include <cstdint> // uint8_t, uint16_t, uint32_t, uint64_t
#include <cstring> // memcpy
#include <limits> // numeric_limits
#include <string> // string

// #include <nlohmann/detail/input/binary_reader.hpp>

// #include <nlohmann/detail/macro_scope.hpp>

// #include <nlohmann/detail/output/output_adapters.hpp>


#include <algorithm> // copy
#include <cstddef> // size_t
#include <ios> // streamsize
#include <iterator> // back_inserter
#include <memory> // shared_ptr, make_shared
#include <ostream> // basic_ostream
#include <string> // basic_string
#include <vector> // vector
// #include <nlohmann/detail/macro_scope.hpp>


namespace nlohmann
{
	namespace detail
	{
		/// abstract output adapter interface
		template<typename CharType> struct output_adapter_protocol
		{
			virtual void write_character(CharType c) = 0;
			virtual void write_characters(const CharType* s, std::size_t length) = 0;
			virtual ~output_adapter_protocol() = default;
		};

		/// a type to simplify interfaces
		template<typename CharType>
		using output_adapter_t = std::shared_ptr<output_adapter_protocol<CharType>>;

		/// output adapter for byte vectors
		template<typename CharType>
		class output_vector_adapter : public output_adapter_protocol<CharType>
		{
		public:
			explicit output_vector_adapter(std::vector<CharType>& vec) noexcept
				: v(vec)
			{}

			void write_character(CharType c) override
			{
				v.push_back(c);
			}

			JSON_HEDLEY_NON_NULL(2)
				void write_characters(const CharType* s, std::size_t length) override
			{
				std::copy(s, s + length, std::back_inserter(v));
			}

		private:
			std::vector<CharType>& v;
		};

		/// output adapter for output streams
		template<typename CharType>
		class output_stream_adapter : public output_adapter_protocol<CharType>
		{
		public:
			explicit output_stream_adapter(std::basic_ostream<CharType>& s) noexcept
				: stream(s)
			{}

			void write_character(CharType c) override
			{
				stream.put(c);
			}

			JSON_HEDLEY_NON_NULL(2)
				void write_characters(const CharType* s, std::size_t length) override
			{
				stream.write(s, static_cast<std::streamsize>(length));
			}

		private:
			std::basic_ostream<CharType>& stream;
		};

		/// output adapter for basic_string
		template<typename CharType, typename StringType = std::basic_string<CharType>>
		class output_string_adapter : public output_adapter_protocol<CharType>
		{
		public:
			explicit output_string_adapter(StringType& s) noexcept
				: str(s)
			{}

			void write_character(CharType c) override
			{
				str.push_back(c);
			}

			JSON_HEDLEY_NON_NULL(2)
				void write_characters(const CharType* s, std::size_t length) override
			{
				str.append(s, length);
			}

		private:
			StringType& str;
		};

		template<typename CharType, typename StringType = std::basic_string<CharType>>
		class output_adapter
		{
		public:
			output_adapter(std::vector<CharType>& vec)
				: oa(std::make_shared<output_vector_adapter<CharType>>(vec)) {}

			output_adapter(std::basic_ostream<CharType>& s)
				: oa(std::make_shared<output_stream_adapter<CharType>>(s)) {}

			output_adapter(StringType& s)
				: oa(std::make_shared<output_string_adapter<CharType, StringType>>(s)) {}

			operator output_adapter_t<CharType>()
			{
				return oa;
			}

		private:
			output_adapter_t<CharType> oa = nullptr;
		};
	}  // namespace detail
}  // namespace nlohmann


namespace nlohmann
{
	namespace detail
	{
		///////////////////
		// binary writer //
		///////////////////

		/*!
		@brief serialization to CBOR and MessagePack values
		*/
		template<typename BasicJsonType, typename CharType>
		class binary_writer
		{
			using string_t = typename BasicJsonType::string_t;

		public:
			/*!
			@brief create a binary writer
			@param[in] adapter  output adapter to write to
			*/
			explicit binary_writer(output_adapter_t<CharType> adapter) : oa(adapter)
			{
				assert(oa);
			}

			/*!
			@param[in] j  JSON value to serialize
			@pre       j.type() == value_t::object
			*/
			void write_bson(const BasicJsonType& j)
			{
				switch (j.type())
				{
				case value_t::object:
				{
					write_bson_object(*j.m_value.object);
					break;
				}

				default:
				{
					JSON_THROW(type_error::create(317, "to serialize to BSON, top-level type must be object, but is " + std::string(j.type_name())));
				}
				}
			}

			/*!
			@param[in] j  JSON value to serialize
			*/
			void write_cbor(const BasicJsonType& j)
			{
				switch (j.type())
				{
				case value_t::null:
				{
					oa->write_character(to_char_type(0xF6));
					break;
				}

				case value_t::boolean:
				{
					oa->write_character(j.m_value.boolean
						? to_char_type(0xF5)
						: to_char_type(0xF4));
					break;
				}

				case value_t::number_integer:
				{
					if (j.m_value.number_integer >= 0)
					{
						// CBOR does not differentiate between positive signed
						// integers and unsigned integers. Therefore, we used the
						// code from the value_t::number_unsigned case here.
						if (j.m_value.number_integer <= 0x17)
						{
							write_number(static_cast<std::uint8_t>(j.m_value.number_integer));
						}
						else if (j.m_value.number_integer <= (std::numeric_limits<std::uint8_t>::max)())
						{
							oa->write_character(to_char_type(0x18));
							write_number(static_cast<std::uint8_t>(j.m_value.number_integer));
						}
						else if (j.m_value.number_integer <= (std::numeric_limits<std::uint16_t>::max)())
						{
							oa->write_character(to_char_type(0x19));
							write_number(static_cast<std::uint16_t>(j.m_value.number_integer));
						}
						else if (j.m_value.number_integer <= (std::numeric_limits<std::uint32_t>::max)())
						{
							oa->write_character(to_char_type(0x1A));
							write_number(static_cast<std::uint32_t>(j.m_value.number_integer));
						}
						else
						{
							oa->write_character(to_char_type(0x1B));
							write_number(static_cast<std::uint64_t>(j.m_value.number_integer));
						}
					}
					else
					{
						// The conversions below encode the sign in the first
						// byte, and the value is converted to a positive number.
						const auto positive_number = -1 - j.m_value.number_integer;
						if (j.m_value.number_integer >= -24)
						{
							write_number(static_cast<std::uint8_t>(0x20 + positive_number));
						}
						else if (positive_number <= (std::numeric_limits<std::uint8_t>::max)())
						{
							oa->write_character(to_char_type(0x38));
							write_number(static_cast<std::uint8_t>(positive_number));
						}
						else if (positive_number <= (std::numeric_limits<std::uint16_t>::max)())
						{
							oa->write_character(to_char_type(0x39));
							write_number(static_cast<std::uint16_t>(positive_number));
						}
						else if (positive_number <= (std::numeric_limits<std::uint32_t>::max)())
						{
							oa->write_character(to_char_type(0x3A));
							write_number(static_cast<std::uint32_t>(positive_number));
						}
						else
						{
							oa->write_character(to_char_type(0x3B));
							write_number(static_cast<std::uint64_t>(positive_number));
						}
					}
					break;
				}

				case value_t::number_unsigned:
				{
					if (j.m_value.number_unsigned <= 0x17)
					{
						write_number(static_cast<std::uint8_t>(j.m_value.number_unsigned));
					}
					else if (j.m_value.number_unsigned <= (std::numeric_limits<std::uint8_t>::max)())
					{
						oa->write_character(to_char_type(0x18));
						write_number(static_cast<std::uint8_t>(j.m_value.number_unsigned));
					}
					else if (j.m_value.number_unsigned <= (std::numeric_limits<std::uint16_t>::max)())
					{
						oa->write_character(to_char_type(0x19));
						write_number(static_cast<std::uint16_t>(j.m_value.number_unsigned));
					}
					else if (j.m_value.number_unsigned <= (std::numeric_limits<std::uint32_t>::max)())
					{
						oa->write_character(to_char_type(0x1A));
						write_number(static_cast<std::uint32_t>(j.m_value.number_unsigned));
					}
					else
					{
						oa->write_character(to_char_type(0x1B));
						write_number(static_cast<std::uint64_t>(j.m_value.number_unsigned));
					}
					break;
				}

				case value_t::number_float:
				{
					oa->write_character(get_cbor_float_prefix(j.m_value.number_float));
					write_number(j.m_value.number_float);
					break;
				}

				case value_t::string:
				{
					// step 1: write control byte and the string length
					const auto N = j.m_value.string->size();
					if (N <= 0x17)
					{
						write_number(static_cast<std::uint8_t>(0x60 + N));
					}
					else if (N <= (std::numeric_limits<std::uint8_t>::max)())
					{
						oa->write_character(to_char_type(0x78));
						write_number(static_cast<std::uint8_t>(N));
					}
					else if (N <= (std::numeric_limits<std::uint16_t>::max)())
					{
						oa->write_character(to_char_type(0x79));
						write_number(static_cast<std::uint16_t>(N));
					}
					else if (N <= (std::numeric_limits<std::uint32_t>::max)())
					{
						oa->write_character(to_char_type(0x7A));
						write_number(static_cast<std::uint32_t>(N));
					}
					// LCOV_EXCL_START
					else if (N <= (std::numeric_limits<std::uint64_t>::max)())
					{
						oa->write_character(to_char_type(0x7B));
						write_number(static_cast<std::uint64_t>(N));
					}
					// LCOV_EXCL_STOP

					// step 2: write the string
					oa->write_characters(
						reinterpret_cast<const CharType*>(j.m_value.string->c_str()),
						j.m_value.string->size());
					break;
				}

				case value_t::array:
				{
					// step 1: write control byte and the array size
					const auto N = j.m_value.array->size();
					if (N <= 0x17)
					{
						write_number(static_cast<std::uint8_t>(0x80 + N));
					}
					else if (N <= (std::numeric_limits<std::uint8_t>::max)())
					{
						oa->write_character(to_char_type(0x98));
						write_number(static_cast<std::uint8_t>(N));
					}
					else if (N <= (std::numeric_limits<std::uint16_t>::max)())
					{
						oa->write_character(to_char_type(0x99));
						write_number(static_cast<std::uint16_t>(N));
					}
					else if (N <= (std::numeric_limits<std::uint32_t>::max)())
					{
						oa->write_character(to_char_type(0x9A));
						write_number(static_cast<std::uint32_t>(N));
					}
					// LCOV_EXCL_START
					else if (N <= (std::numeric_limits<std::uint64_t>::max)())
					{
						oa->write_character(to_char_type(0x9B));
						write_number(static_cast<std::uint64_t>(N));
					}
					// LCOV_EXCL_STOP

					// step 2: write each element
					for (const auto& el : *j.m_value.array)
					{
						write_cbor(el);
					}
					break;
				}

				case value_t::object:
				{
					// step 1: write control byte and the object size
					const auto N = j.m_value.object->size();
					if (N <= 0x17)
					{
						write_number(static_cast<std::uint8_t>(0xA0 + N));
					}
					else if (N <= (std::numeric_limits<std::uint8_t>::max)())
					{
						oa->write_character(to_char_type(0xB8));
						write_number(static_cast<std::uint8_t>(N));
					}
					else if (N <= (std::numeric_limits<std::uint16_t>::max)())
					{
						oa->write_character(to_char_type(0xB9));
						write_number(static_cast<std::uint16_t>(N));
					}
					else if (N <= (std::numeric_limits<std::uint32_t>::max)())
					{
						oa->write_character(to_char_type(0xBA));
						write_number(static_cast<std::uint32_t>(N));
					}
					// LCOV_EXCL_START
					else if (N <= (std::numeric_limits<std::uint64_t>::max)())
					{
						oa->write_character(to_char_type(0xBB));
						write_number(static_cast<std::uint64_t>(N));
					}
					// LCOV_EXCL_STOP

					// step 2: write each element
					for (const auto& el : *j.m_value.object)
					{
						write_cbor(el.first);
						write_cbor(el.second);
					}
					break;
				}

				default:
					break;
				}
			}

			/*!
			@param[in] j  JSON value to serialize
			*/
			void write_msgpack(const BasicJsonType& j)
			{
				switch (j.type())
				{
				case value_t::null: // nil
				{
					oa->write_character(to_char_type(0xC0));
					break;
				}

				case value_t::boolean: // true and false
				{
					oa->write_character(j.m_value.boolean
						? to_char_type(0xC3)
						: to_char_type(0xC2));
					break;
				}

				case value_t::number_integer:
				{
					if (j.m_value.number_integer >= 0)
					{
						// MessagePack does not differentiate between positive
						// signed integers and unsigned integers. Therefore, we used
						// the code from the value_t::number_unsigned case here.
						if (j.m_value.number_unsigned < 128)
						{
							// positive fixnum
							write_number(static_cast<std::uint8_t>(j.m_value.number_integer));
						}
						else if (j.m_value.number_unsigned <= (std::numeric_limits<std::uint8_t>::max)())
						{
							// uint 8
							oa->write_character(to_char_type(0xCC));
							write_number(static_cast<std::uint8_t>(j.m_value.number_integer));
						}
						else if (j.m_value.number_unsigned <= (std::numeric_limits<std::uint16_t>::max)())
						{
							// uint 16
							oa->write_character(to_char_type(0xCD));
							write_number(static_cast<std::uint16_t>(j.m_value.number_integer));
						}
						else if (j.m_value.number_unsigned <= (std::numeric_limits<std::uint32_t>::max)())
						{
							// uint 32
							oa->write_character(to_char_type(0xCE));
							write_number(static_cast<std::uint32_t>(j.m_value.number_integer));
						}
						else if (j.m_value.number_unsigned <= (std::numeric_limits<std::uint64_t>::max)())
						{
							// uint 64
							oa->write_character(to_char_type(0xCF));
							write_number(static_cast<std::uint64_t>(j.m_value.number_integer));
						}
					}
					else
					{
						if (j.m_value.number_integer >= -32)
						{
							// negative fixnum
							write_number(static_cast<std::int8_t>(j.m_value.number_integer));
						}
						else if (j.m_value.number_integer >= (std::numeric_limits<std::int8_t>::min)() and
							j.m_value.number_integer <= (std::numeric_limits<std::int8_t>::max)())
						{
							// int 8
							oa->write_character(to_char_type(0xD0));
							write_number(static_cast<std::int8_t>(j.m_value.number_integer));
						}
						else if (j.m_value.number_integer >= (std::numeric_limits<std::int16_t>::min)() and
							j.m_value.number_integer <= (std::numeric_limits<std::int16_t>::max)())
						{
							// int 16
							oa->write_character(to_char_type(0xD1));
							write_number(static_cast<std::int16_t>(j.m_value.number_integer));
						}
						else if (j.m_value.number_integer >= (std::numeric_limits<std::int32_t>::min)() and
							j.m_value.number_integer <= (std::numeric_limits<std::int32_t>::max)())
						{
							// int 32
							oa->write_character(to_char_type(0xD2));
							write_number(static_cast<std::int32_t>(j.m_value.number_integer));
						}
						else if (j.m_value.number_integer >= (std::numeric_limits<std::int64_t>::min)() and
							j.m_value.number_integer <= (std::numeric_limits<std::int64_t>::max)())
						{
							// int 64
							oa->write_character(to_char_type(0xD3));
							write_number(static_cast<std::int64_t>(j.m_value.number_integer));
						}
					}
					break;
				}

				case value_t::number_unsigned:
				{
					if (j.m_value.number_unsigned < 128)
					{
						// positive fixnum
						write_number(static_cast<std::uint8_t>(j.m_value.number_integer));
					}
					else if (j.m_value.number_unsigned <= (std::numeric_limits<std::uint8_t>::max)())
					{
						// uint 8
						oa->write_character(to_char_type(0xCC));
						write_number(static_cast<std::uint8_t>(j.m_value.number_integer));
					}
					else if (j.m_value.number_unsigned <= (std::numeric_limits<std::uint16_t>::max)())
					{
						// uint 16
						oa->write_character(to_char_type(0xCD));
						write_number(static_cast<std::uint16_t>(j.m_value.number_integer));
					}
					else if (j.m_value.number_unsigned <= (std::numeric_limits<std::uint32_t>::max)())
					{
						// uint 32
						oa->write_character(to_char_type(0xCE));
						write_number(static_cast<std::uint32_t>(j.m_value.number_integer));
					}
					else if (j.m_value.number_unsigned <= (std::numeric_limits<std::uint64_t>::max)())
					{
						// uint 64
						oa->write_character(to_char_type(0xCF));
						write_number(static_cast<std::uint64_t>(j.m_value.number_integer));
					}
					break;
				}

				case value_t::number_float:
				{
					oa->write_character(get_msgpack_float_prefix(j.m_value.number_float));
					write_number(j.m_value.number_float);
					break;
				}

				case value_t::string:
				{
					// step 1: write control byte and the string length
					const auto N = j.m_value.string->size();
					if (N <= 31)
					{
						// fixstr
						write_number(static_cast<std::uint8_t>(0xA0 | N));
					}
					else if (N <= (std::numeric_limits<std::uint8_t>::max)())
					{
						// str 8
						oa->write_character(to_char_type(0xD9));
						write_number(static_cast<std::uint8_t>(N));
					}
					else if (N <= (std::numeric_limits<std::uint16_t>::max)())
					{
						// str 16
						oa->write_character(to_char_type(0xDA));
						write_number(static_cast<std::uint16_t>(N));
					}
					else if (N <= (std::numeric_limits<std::uint32_t>::max)())
					{
						// str 32
						oa->write_character(to_char_type(0xDB));
						write_number(static_cast<std::uint32_t>(N));
					}

					// step 2: write the string
					oa->write_characters(
						reinterpret_cast<const CharType*>(j.m_value.string->c_str()),
						j.m_value.string->size());
					break;
				}

				case value_t::array:
				{
					// step 1: write control byte and the array size
					const auto N = j.m_value.array->size();
					if (N <= 15)
					{
						// fixarray
						write_number(static_cast<std::uint8_t>(0x90 | N));
					}
					else if (N <= (std::numeric_limits<std::uint16_t>::max)())
					{
						// array 16
						oa->write_character(to_char_type(0xDC));
						write_number(static_cast<std::uint16_t>(N));
					}
					else if (N <= (std::numeric_limits<std::uint32_t>::max)())
					{
						// array 32
						oa->write_character(to_char_type(0xDD));
						write_number(static_cast<std::uint32_t>(N));
					}

					// step 2: write each element
					for (const auto& el : *j.m_value.array)
					{
						write_msgpack(el);
					}
					break;
				}

				case value_t::object:
				{
					// step 1: write control byte and the object size
					const auto N = j.m_value.object->size();
					if (N <= 15)
					{
						// fixmap
						write_number(static_cast<std::uint8_t>(0x80 | (N & 0xF)));
					}
					else if (N <= (std::numeric_limits<std::uint16_t>::max)())
					{
						// map 16
						oa->write_character(to_char_type(0xDE));
						write_number(static_cast<std::uint16_t>(N));
					}
					else if (N <= (std::numeric_limits<std::uint32_t>::max)())
					{
						// map 32
						oa->write_character(to_char_type(0xDF));
						write_number(static_cast<std::uint32_t>(N));
					}

					// step 2: write each element
					for (const auto& el : *j.m_value.object)
					{
						write_msgpack(el.first);
						write_msgpack(el.second);
					}
					break;
				}

				default:
					break;
				}
			}

			/*!
			@param[in] j  JSON value to serialize
			@param[in] use_count   whether to use '#' prefixes (optimized format)
			@param[in] use_type    whether to use '$' prefixes (optimized format)
			@param[in] add_prefix  whether prefixes need to be used for this value
			*/
			void write_ubjson(const BasicJsonType& j, const bool use_count,
				const bool use_type, const bool add_prefix = true)
			{
				switch (j.type())
				{
				case value_t::null:
				{
					if (add_prefix)
					{
						oa->write_character(to_char_type('Z'));
					}
					break;
				}

				case value_t::boolean:
				{
					if (add_prefix)
					{
						oa->write_character(j.m_value.boolean
							? to_char_type('T')
							: to_char_type('F'));
					}
					break;
				}

				case value_t::number_integer:
				{
					write_number_with_ubjson_prefix(j.m_value.number_integer, add_prefix);
					break;
				}

				case value_t::number_unsigned:
				{
					write_number_with_ubjson_prefix(j.m_value.number_unsigned, add_prefix);
					break;
				}

				case value_t::number_float:
				{
					write_number_with_ubjson_prefix(j.m_value.number_float, add_prefix);
					break;
				}

				case value_t::string:
				{
					if (add_prefix)
					{
						oa->write_character(to_char_type('S'));
					}
					write_number_with_ubjson_prefix(j.m_value.string->size(), true);
					oa->write_characters(
						reinterpret_cast<const CharType*>(j.m_value.string->c_str()),
						j.m_value.string->size());
					break;
				}

				case value_t::array:
				{
					if (add_prefix)
					{
						oa->write_character(to_char_type('['));
					}

					bool prefix_required = true;
					if (use_type and not j.m_value.array->empty())
					{
						assert(use_count);
						const CharType first_prefix = ubjson_prefix(j.front());
						const bool same_prefix = std::all_of(j.begin() + 1, j.end(),
							[this, first_prefix](const BasicJsonType& v)
							{
								return ubjson_prefix(v) == first_prefix;
							});

						if (same_prefix)
						{
							prefix_required = false;
							oa->write_character(to_char_type('$'));
							oa->write_character(first_prefix);
						}
					}

					if (use_count)
					{
						oa->write_character(to_char_type('#'));
						write_number_with_ubjson_prefix(j.m_value.array->size(), true);
					}

					for (const auto& el : *j.m_value.array)
					{
						write_ubjson(el, use_count, use_type, prefix_required);
					}

					if (not use_count)
					{
						oa->write_character(to_char_type(']'));
					}

					break;
				}

				case value_t::object:
				{
					if (add_prefix)
					{
						oa->write_character(to_char_type('{'));
					}

					bool prefix_required = true;
					if (use_type and not j.m_value.object->empty())
					{
						assert(use_count);
						const CharType first_prefix = ubjson_prefix(j.front());
						const bool same_prefix = std::all_of(j.begin(), j.end(),
							[this, first_prefix](const BasicJsonType& v)
							{
								return ubjson_prefix(v) == first_prefix;
							});

						if (same_prefix)
						{
							prefix_required = false;
							oa->write_character(to_char_type('$'));
							oa->write_character(first_prefix);
						}
					}

					if (use_count)
					{
						oa->write_character(to_char_type('#'));
						write_number_with_ubjson_prefix(j.m_value.object->size(), true);
					}

					for (const auto& el : *j.m_value.object)
					{
						write_number_with_ubjson_prefix(el.first.size(), true);
						oa->write_characters(
							reinterpret_cast<const CharType*>(el.first.c_str()),
							el.first.size());
						write_ubjson(el.second, use_count, use_type, prefix_required);
					}

					if (not use_count)
					{
						oa->write_character(to_char_type('}'));
					}

					break;
				}

				default:
					break;
				}
			}

		private:
			//////////
			// BSON //
			//////////

			/*!
			@return The size of a BSON document entry header, including the id marker
					and the entry name size (and its null-terminator).
			*/
			static std::size_t calc_bson_entry_header_size(const string_t& name)
			{
				const auto it = name.find(static_cast<typename string_t::value_type>(0));
				if (JSON_HEDLEY_UNLIKELY(it != BasicJsonType::string_t::npos))
				{
					JSON_THROW(out_of_range::create(409,
						"BSON key cannot contain code point U+0000 (at byte " + std::to_string(it) + ")"));
				}

				return /*id*/ 1ul + name.size() + /*zero-terminator*/1u;
			}

			/*!
			@brief Writes the given @a element_type and @a name to the output adapter
			*/
			void write_bson_entry_header(const string_t& name,
				const std::uint8_t element_type)
			{
				oa->write_character(to_char_type(element_type)); // boolean
				oa->write_characters(
					reinterpret_cast<const CharType*>(name.c_str()),
					name.size() + 1u);
			}

			/*!
			@brief Writes a BSON element with key @a name and boolean value @a value
			*/
			void write_bson_boolean(const string_t& name,
				const bool value)
			{
				write_bson_entry_header(name, 0x08);
				oa->write_character(value ? to_char_type(0x01) : to_char_type(0x00));
			}

			/*!
			@brief Writes a BSON element with key @a name and double value @a value
			*/
			void write_bson_double(const string_t& name,
				const double value)
			{
				write_bson_entry_header(name, 0x01);
				write_number<double, true>(value);
			}

			/*!
			@return The size of the BSON-encoded string in @a value
			*/
			static std::size_t calc_bson_string_size(const string_t& value)
			{
				return sizeof(std::int32_t) + value.size() + 1ul;
			}

			/*!
			@brief Writes a BSON element with key @a name and string value @a value
			*/
			void write_bson_string(const string_t& name,
				const string_t& value)
			{
				write_bson_entry_header(name, 0x02);

				write_number<std::int32_t, true>(static_cast<std::int32_t>(value.size() + 1ul));
				oa->write_characters(
					reinterpret_cast<const CharType*>(value.c_str()),
					value.size() + 1);
			}

			/*!
			@brief Writes a BSON element with key @a name and null value
			*/
			void write_bson_null(const string_t& name)
			{
				write_bson_entry_header(name, 0x0A);
			}

			/*!
			@return The size of the BSON-encoded integer @a value
			*/
			static std::size_t calc_bson_integer_size(const std::int64_t value)
			{
				return (std::numeric_limits<std::int32_t>::min)() <= value and value <= (std::numeric_limits<std::int32_t>::max)()
					? sizeof(std::int32_t)
					: sizeof(std::int64_t);
			}

			/*!
			@brief Writes a BSON element with key @a name and integer @a value
			*/
			void write_bson_integer(const string_t& name,
				const std::int64_t value)
			{
				if ((std::numeric_limits<std::int32_t>::min)() <= value and value <= (std::numeric_limits<std::int32_t>::max)())
				{
					write_bson_entry_header(name, 0x10); // int32
					write_number<std::int32_t, true>(static_cast<std::int32_t>(value));
				}
				else
				{
					write_bson_entry_header(name, 0x12); // int64
					write_number<std::int64_t, true>(static_cast<std::int64_t>(value));
				}
			}

			/*!
			@return The size of the BSON-encoded unsigned integer in @a j
			*/
			static constexpr std::size_t calc_bson_unsigned_size(const std::uint64_t value) noexcept
			{
				return (value <= static_cast<std::uint64_t>((std::numeric_limits<std::int32_t>::max)()))
					? sizeof(std::int32_t)
					: sizeof(std::int64_t);
			}

			/*!
			@brief Writes a BSON element with key @a name and unsigned @a value
			*/
			void write_bson_unsigned(const string_t& name,
				const std::uint64_t value)
			{
				if (value <= static_cast<std::uint64_t>((std::numeric_limits<std::int32_t>::max)()))
				{
					write_bson_entry_header(name, 0x10 /* int32 */);
					write_number<std::int32_t, true>(static_cast<std::int32_t>(value));
				}
				else if (value <= static_cast<std::uint64_t>((std::numeric_limits<std::int64_t>::max)()))
				{
					write_bson_entry_header(name, 0x12 /* int64 */);
					write_number<std::int64_t, true>(static_cast<std::int64_t>(value));
				}
				else
				{
					JSON_THROW(out_of_range::create(407, "integer number " + std::to_string(value) + " cannot be represented by BSON as it does not fit int64"));
				}
			}

			/*!
			@brief Writes a BSON element with key @a name and object @a value
			*/
			void write_bson_object_entry(const string_t& name,
				const typename BasicJsonType::object_t& value)
			{
				write_bson_entry_header(name, 0x03); // object
				write_bson_object(value);
			}

			/*!
			@return The size of the BSON-encoded array @a value
			*/
			static std::size_t calc_bson_array_size(const typename BasicJsonType::array_t& value)
			{
				std::size_t array_index = 0ul;

				const std::size_t embedded_document_size = std::accumulate(std::begin(value), std::end(value), 0ul, [&array_index](std::size_t result, const typename BasicJsonType::array_t::value_type& el)
					{
						return result + calc_bson_element_size(std::to_string(array_index++), el);
					});

				return sizeof(std::int32_t) + embedded_document_size + 1ul;
			}

			/*!
			@brief Writes a BSON element with key @a name and array @a value
			*/
			void write_bson_array(const string_t& name,
				const typename BasicJsonType::array_t& value)
			{
				write_bson_entry_header(name, 0x04); // array
				write_number<std::int32_t, true>(static_cast<std::int32_t>(calc_bson_array_size(value)));

				std::size_t array_index = 0ul;

				for (const auto& el : value)
				{
					write_bson_element(std::to_string(array_index++), el);
				}

				oa->write_character(to_char_type(0x00));
			}

			/*!
			@brief Calculates the size necessary to serialize the JSON value @a j with its @a name
			@return The calculated size for the BSON document entry for @a j with the given @a name.
			*/
			static std::size_t calc_bson_element_size(const string_t& name,
				const BasicJsonType& j)
			{
				const auto header_size = calc_bson_entry_header_size(name);
				switch (j.type())
				{
				case value_t::object:
					return header_size + calc_bson_object_size(*j.m_value.object);

				case value_t::array:
					return header_size + calc_bson_array_size(*j.m_value.array);

				case value_t::boolean:
					return header_size + 1ul;

				case value_t::number_float:
					return header_size + 8ul;

				case value_t::number_integer:
					return header_size + calc_bson_integer_size(j.m_value.number_integer);

				case value_t::number_unsigned:
					return header_size + calc_bson_unsigned_size(j.m_value.number_unsigned);

				case value_t::string:
					return header_size + calc_bson_string_size(*j.m_value.string);

				case value_t::null:
					return header_size + 0ul;

					// LCOV_EXCL_START
				default:
					assert(false);
					return 0ul;
					// LCOV_EXCL_STOP
				}
			}

			/*!
			@brief Serializes the JSON value @a j to BSON and associates it with the
				   key @a name.
			@param name The name to associate with the JSON entity @a j within the
						current BSON document
			@return The size of the BSON entry
			*/
			void write_bson_element(const string_t& name,
				const BasicJsonType& j)
			{
				switch (j.type())
				{
				case value_t::object:
					return write_bson_object_entry(name, *j.m_value.object);

				case value_t::array:
					return write_bson_array(name, *j.m_value.array);

				case value_t::boolean:
					return write_bson_boolean(name, j.m_value.boolean);

				case value_t::number_float:
					return write_bson_double(name, j.m_value.number_float);

				case value_t::number_integer:
					return write_bson_integer(name, j.m_value.number_integer);

				case value_t::number_unsigned:
					return write_bson_unsigned(name, j.m_value.number_unsigned);

				case value_t::string:
					return write_bson_string(name, *j.m_value.string);

				case value_t::null:
					return write_bson_null(name);

					// LCOV_EXCL_START
				default:
					assert(false);
					return;
					// LCOV_EXCL_STOP
				}
			}

			/*!
			@brief Calculates the size of the BSON serialization of the given
				   JSON-object @a j.
			@param[in] j  JSON value to serialize
			@pre       j.type() == value_t::object
			*/
			static std::size_t calc_bson_object_size(const typename BasicJsonType::object_t& value)
			{
				std::size_t document_size = std::accumulate(value.begin(), value.end(), 0ul,
					[](size_t result, const typename BasicJsonType::object_t::value_type& el)
					{
						return result += calc_bson_element_size(el.first, el.second);
					});

				return sizeof(std::int32_t) + document_size + 1ul;
			}

			/*!
			@param[in] j  JSON value to serialize
			@pre       j.type() == value_t::object
			*/
			void write_bson_object(const typename BasicJsonType::object_t& value)
			{
				write_number<std::int32_t, true>(static_cast<std::int32_t>(calc_bson_object_size(value)));

				for (const auto& el : value)
				{
					write_bson_element(el.first, el.second);
				}

				oa->write_character(to_char_type(0x00));
			}

			//////////
			// CBOR //
			//////////

			static constexpr CharType get_cbor_float_prefix(float /*unused*/)
			{
				return to_char_type(0xFA);  // Single-Precision Float
			}

			static constexpr CharType get_cbor_float_prefix(double /*unused*/)
			{
				return to_char_type(0xFB);  // Double-Precision Float
			}

			/////////////
			// MsgPack //
			/////////////

			static constexpr CharType get_msgpack_float_prefix(float /*unused*/)
			{
				return to_char_type(0xCA);  // float 32
			}

			static constexpr CharType get_msgpack_float_prefix(double /*unused*/)
			{
				return to_char_type(0xCB);  // float 64
			}

			////////////
			// UBJSON //
			////////////

			// UBJSON: write number (floating point)
			template<typename NumberType, typename std::enable_if<
				std::is_floating_point<NumberType>::value, int>::type = 0>
				void write_number_with_ubjson_prefix(const NumberType n,
					const bool add_prefix)
			{
				if (add_prefix)
				{
					oa->write_character(get_ubjson_float_prefix(n));
				}
				write_number(n);
			}

			// UBJSON: write number (unsigned integer)
			template<typename NumberType, typename std::enable_if<
				std::is_unsigned<NumberType>::value, int>::type = 0>
				void write_number_with_ubjson_prefix(const NumberType n,
					const bool add_prefix)
			{
				if (n <= static_cast<std::uint64_t>((std::numeric_limits<std::int8_t>::max)()))
				{
					if (add_prefix)
					{
						oa->write_character(to_char_type('i'));  // int8
					}
					write_number(static_cast<std::uint8_t>(n));
				}
				else if (n <= (std::numeric_limits<std::uint8_t>::max)())
				{
					if (add_prefix)
					{
						oa->write_character(to_char_type('U'));  // uint8
					}
					write_number(static_cast<std::uint8_t>(n));
				}
				else if (n <= static_cast<std::uint64_t>((std::numeric_limits<std::int16_t>::max)()))
				{
					if (add_prefix)
					{
						oa->write_character(to_char_type('I'));  // int16
					}
					write_number(static_cast<std::int16_t>(n));
				}
				else if (n <= static_cast<std::uint64_t>((std::numeric_limits<std::int32_t>::max)()))
				{
					if (add_prefix)
					{
						oa->write_character(to_char_type('l'));  // int32
					}
					write_number(static_cast<std::int32_t>(n));
				}
				else if (n <= static_cast<std::uint64_t>((std::numeric_limits<std::int64_t>::max)()))
				{
					if (add_prefix)
					{
						oa->write_character(to_char_type('L'));  // int64
					}
					write_number(static_cast<std::int64_t>(n));
				}
				else
				{
					JSON_THROW(out_of_range::create(407, "integer number " + std::to_string(n) + " cannot be represented by UBJSON as it does not fit int64"));
				}
			}

			// UBJSON: write number (signed integer)
			template<typename NumberType, typename std::enable_if<
				std::is_signed<NumberType>::value and
				not std::is_floating_point<NumberType>::value, int>::type = 0>
				void write_number_with_ubjson_prefix(const NumberType n,
					const bool add_prefix)
			{
				if ((std::numeric_limits<std::int8_t>::min)() <= n and n <= (std::numeric_limits<std::int8_t>::max)())
				{
					if (add_prefix)
					{
						oa->write_character(to_char_type('i'));  // int8
					}
					write_number(static_cast<std::int8_t>(n));
				}
				else if (static_cast<std::int64_t>((std::numeric_limits<std::uint8_t>::min)()) <= n and n <= static_cast<std::int64_t>((std::numeric_limits<std::uint8_t>::max)()))
				{
					if (add_prefix)
					{
						oa->write_character(to_char_type('U'));  // uint8
					}
					write_number(static_cast<std::uint8_t>(n));
				}
				else if ((std::numeric_limits<std::int16_t>::min)() <= n and n <= (std::numeric_limits<std::int16_t>::max)())
				{
					if (add_prefix)
					{
						oa->write_character(to_char_type('I'));  // int16
					}
					write_number(static_cast<std::int16_t>(n));
				}
				else if ((std::numeric_limits<std::int32_t>::min)() <= n and n <= (std::numeric_limits<std::int32_t>::max)())
				{
					if (add_prefix)
					{
						oa->write_character(to_char_type('l'));  // int32
					}
					write_number(static_cast<std::int32_t>(n));
				}
				else if ((std::numeric_limits<std::int64_t>::min)() <= n and n <= (std::numeric_limits<std::int64_t>::max)())
				{
					if (add_prefix)
					{
						oa->write_character(to_char_type('L'));  // int64
					}
					write_number(static_cast<std::int64_t>(n));
				}
				// LCOV_EXCL_START
				else
				{
					JSON_THROW(out_of_range::create(407, "integer number " + std::to_string(n) + " cannot be represented by UBJSON as it does not fit int64"));
				}
				// LCOV_EXCL_STOP
			}

			/*!
			@brief determine the type prefix of container values
			@note This function does not need to be 100% accurate when it comes to
				  integer limits. In case a number exceeds the limits of int64_t,
				  this will be detected by a later call to function
				  write_number_with_ubjson_prefix. Therefore, we return 'L' for any
				  value that does not fit the previous limits.
			*/
			CharType ubjson_prefix(const BasicJsonType& j) const noexcept
			{
				switch (j.type())
				{
				case value_t::null:
					return 'Z';

				case value_t::boolean:
					return j.m_value.boolean ? 'T' : 'F';

				case value_t::number_integer:
				{
					if ((std::numeric_limits<std::int8_t>::min)() <= j.m_value.number_integer and j.m_value.number_integer <= (std::numeric_limits<std::int8_t>::max)())
					{
						return 'i';
					}
					if ((std::numeric_limits<std::uint8_t>::min)() <= j.m_value.number_integer and j.m_value.number_integer <= (std::numeric_limits<std::uint8_t>::max)())
					{
						return 'U';
					}
					if ((std::numeric_limits<std::int16_t>::min)() <= j.m_value.number_integer and j.m_value.number_integer <= (std::numeric_limits<std::int16_t>::max)())
					{
						return 'I';
					}
					if ((std::numeric_limits<std::int32_t>::min)() <= j.m_value.number_integer and j.m_value.number_integer <= (std::numeric_limits<std::int32_t>::max)())
					{
						return 'l';
					}
					// no check and assume int64_t (see note above)
					return 'L';
				}

				case value_t::number_unsigned:
				{
					if (j.m_value.number_unsigned <= static_cast<std::uint64_t>((std::numeric_limits<std::int8_t>::max)()))
					{
						return 'i';
					}
					if (j.m_value.number_unsigned <= static_cast<std::uint64_t>((std::numeric_limits<std::uint8_t>::max)()))
					{
						return 'U';
					}
					if (j.m_value.number_unsigned <= static_cast<std::uint64_t>((std::numeric_limits<std::int16_t>::max)()))
					{
						return 'I';
					}
					if (j.m_value.number_unsigned <= static_cast<std::uint64_t>((std::numeric_limits<std::int32_t>::max)()))
					{
						return 'l';
					}
					// no check and assume int64_t (see note above)
					return 'L';
				}

				case value_t::number_float:
					return get_ubjson_float_prefix(j.m_value.number_float);

				case value_t::string:
					return 'S';

				case value_t::array:
					return '[';

				case value_t::object:
					return '{';

				default:  // discarded values
					return 'N';
				}
			}

			static constexpr CharType get_ubjson_float_prefix(float /*unused*/)
			{
				return 'd';  // float 32
			}

			static constexpr CharType get_ubjson_float_prefix(double /*unused*/)
			{
				return 'D';  // float 64
			}

			///////////////////////
			// Utility functions //
			///////////////////////

			/*
			@brief write a number to output input
			@param[in] n number of type @a NumberType
			@tparam NumberType the type of the number
			@tparam OutputIsLittleEndian Set to true if output data is
										 required to be little endian
			@note This function needs to respect the system's endianess, because bytes
				  in CBOR, MessagePack, and UBJSON are stored in network order (big
				  endian) and therefore need reordering on little endian systems.
			*/
			template<typename NumberType, bool OutputIsLittleEndian = false>
			void write_number(const NumberType n)
			{
				// step 1: write number to array of length NumberType
				std::array<CharType, sizeof(NumberType)> vec;
				std::memcpy(vec.data(), &n, sizeof(NumberType));

				// step 2: write array to output (with possible reordering)
				if (is_little_endian != OutputIsLittleEndian)
				{
					// reverse byte order prior to conversion if necessary
					std::reverse(vec.begin(), vec.end());
				}

				oa->write_characters(vec.data(), sizeof(NumberType));
			}

		public:
			// The following to_char_type functions are implement the conversion
			// between uint8_t and CharType. In case CharType is not unsigned,
			// such a conversion is required to allow values greater than 128.
			// See <https://github.com/nlohmann/json/issues/1286> for a discussion.
			template < typename C = CharType,
				enable_if_t < std::is_signed<C>::value and std::is_signed<char>::value > * = nullptr >
				static constexpr CharType to_char_type(std::uint8_t x) noexcept
			{
				return *reinterpret_cast<char*>(&x);
			}

			template < typename C = CharType,
				enable_if_t < std::is_signed<C>::value and std::is_unsigned<char>::value > * = nullptr >
				static CharType to_char_type(std::uint8_t x) noexcept
			{
				static_assert(sizeof(std::uint8_t) == sizeof(CharType), "size of CharType must be equal to std::uint8_t");
				static_assert(std::is_pod<CharType>::value, "CharType must be POD");
				CharType result;
				std::memcpy(&result, &x, sizeof(x));
				return result;
			}

			template<typename C = CharType,
				enable_if_t<std::is_unsigned<C>::value> * = nullptr>
				static constexpr CharType to_char_type(std::uint8_t x) noexcept
			{
				return x;
			}

			template < typename InputCharType, typename C = CharType,
				enable_if_t <
				std::is_signed<C>::value and
				std::is_signed<char>::value and
				std::is_same<char, typename std::remove_cv<InputCharType>::type>::value
			> * = nullptr >
				static constexpr CharType to_char_type(InputCharType x) noexcept
			{
				return x;
			}

		private:
			/// whether we can assume little endianess
			const bool is_little_endian = binary_reader<BasicJsonType>::little_endianess();

			/// the output
			output_adapter_t<CharType> oa = nullptr;
		};
	}  // namespace detail
}  // namespace nlohmann

// #include <nlohmann/detail/output/output_adapters.hpp>

// #include <nlohmann/detail/output/serializer.hpp>


#include <algorithm> // reverse, remove, fill, find, none_of
#include <array> // array
#include <cassert> // assert
#include <ciso646> // and, or
#include <clocale> // localeconv, lconv
#include <cmath> // labs, isfinite, isnan, signbit
#include <cstddef> // size_t, ptrdiff_t
#include <cstdint> // uint8_t
#include <cstdio> // snprintf
#include <limits> // numeric_limits
#include <string> // string
#include <type_traits> // is_same
#include <utility> // move

// #include <nlohmann/detail/conversions/to_chars.hpp>


#include <array> // array
#include <cassert> // assert
#include <ciso646> // or, and, not
#include <cmath>   // signbit, isfinite
#include <cstdint> // intN_t, uintN_t
#include <cstring> // memcpy, memmove
#include <limits> // numeric_limits
#include <type_traits> // conditional
// #include <nlohmann/detail/macro_scope.hpp>


namespace nlohmann
{
	namespace detail
	{

		/*!
		@brief implements the Grisu2 algorithm for binary to decimal floating-point
		conversion.
		This implementation is a slightly modified version of the reference
		implementation which may be obtained from
		http://florian.loitsch.com/publications (bench.tar.gz).
		The code is distributed under the MIT license, Copyright (c) 2009 Florian Loitsch.
		For a detailed description of the algorithm see:
		[1] Loitsch, "Printing Floating-Point Numbers Quickly and Accurately with
			Integers", Proceedings of the ACM SIGPLAN 2010 Conference on Programming
			Language Design and Implementation, PLDI 2010
		[2] Burger, Dybvig, "Printing Floating-Point Numbers Quickly and Accurately",
			Proceedings of the ACM SIGPLAN 1996 Conference on Programming Language
			Design and Implementation, PLDI 1996
		*/
		namespace dtoa_impl
		{

			template <typename Target, typename Source>
			Target reinterpret_bits(const Source source)
			{
				static_assert(sizeof(Target) == sizeof(Source), "size mismatch");

				Target target;
				std::memcpy(&target, &source, sizeof(Source));
				return target;
			}

			struct diyfp // f * 2^e
			{
				static constexpr int kPrecision = 64; // = q

				std::uint64_t f = 0;
				int e = 0;

				constexpr diyfp(std::uint64_t f_, int e_) noexcept : f(f_), e(e_) {}

				/*!
				@brief returns x - y
				@pre x.e == y.e and x.f >= y.f
				*/
				static diyfp sub(const diyfp& x, const diyfp& y) noexcept
				{
					assert(x.e == y.e);
					assert(x.f >= y.f);

					return { x.f - y.f, x.e };
				}

				/*!
				@brief returns x * y
				@note The result is rounded. (Only the upper q bits are returned.)
				*/
				static diyfp mul(const diyfp& x, const diyfp& y) noexcept
				{
					static_assert(kPrecision == 64, "internal error");

					// Computes:
					//  f = round((x.f * y.f) / 2^q)
					//  e = x.e + y.e + q

					// Emulate the 64-bit * 64-bit multiplication:
					//
					// p = u * v
					//   = (u_lo + 2^32 u_hi) (v_lo + 2^32 v_hi)
					//   = (u_lo v_lo         ) + 2^32 ((u_lo v_hi         ) + (u_hi v_lo         )) + 2^64 (u_hi v_hi         )
					//   = (p0                ) + 2^32 ((p1                ) + (p2                )) + 2^64 (p3                )
					//   = (p0_lo + 2^32 p0_hi) + 2^32 ((p1_lo + 2^32 p1_hi) + (p2_lo + 2^32 p2_hi)) + 2^64 (p3                )
					//   = (p0_lo             ) + 2^32 (p0_hi + p1_lo + p2_lo                      ) + 2^64 (p1_hi + p2_hi + p3)
					//   = (p0_lo             ) + 2^32 (Q                                          ) + 2^64 (H                 )
					//   = (p0_lo             ) + 2^32 (Q_lo + 2^32 Q_hi                           ) + 2^64 (H                 )
					//
					// (Since Q might be larger than 2^32 - 1)
					//
					//   = (p0_lo + 2^32 Q_lo) + 2^64 (Q_hi + H)
					//
					// (Q_hi + H does not overflow a 64-bit int)
					//
					//   = p_lo + 2^64 p_hi

					const std::uint64_t u_lo = x.f & 0xFFFFFFFFu;
					const std::uint64_t u_hi = x.f >> 32u;
					const std::uint64_t v_lo = y.f & 0xFFFFFFFFu;
					const std::uint64_t v_hi = y.f >> 32u;

					const std::uint64_t p0 = u_lo * v_lo;
					const std::uint64_t p1 = u_lo * v_hi;
					const std::uint64_t p2 = u_hi * v_lo;
					const std::uint64_t p3 = u_hi * v_hi;

					const std::uint64_t p0_hi = p0 >> 32u;
					const std::uint64_t p1_lo = p1 & 0xFFFFFFFFu;
					const std::uint64_t p1_hi = p1 >> 32u;
					const std::uint64_t p2_lo = p2 & 0xFFFFFFFFu;
					const std::uint64_t p2_hi = p2 >> 32u;

					std::uint64_t Q = p0_hi + p1_lo + p2_lo;

					// The full product might now be computed as
					//
					// p_hi = p3 + p2_hi + p1_hi + (Q >> 32)
					// p_lo = p0_lo + (Q << 32)
					//
					// But in this particular case here, the full p_lo is not required.
					// Effectively we only need to add the highest bit in p_lo to p_hi (and
					// Q_hi + 1 does not overflow).

					Q += std::uint64_t{ 1 } << (64u - 32u - 1u); // round, ties up

					const std::uint64_t h = p3 + p2_hi + p1_hi + (Q >> 32u);

					return { h, x.e + y.e + 64 };
				}

				/*!
				@brief normalize x such that the significand is >= 2^(q-1)
				@pre x.f != 0
				*/
				static diyfp normalize(diyfp x) noexcept
				{
					assert(x.f != 0);

					while ((x.f >> 63u) == 0)
					{
						x.f <<= 1u;
						x.e--;
					}

					return x;
				}

				/*!
				@brief normalize x such that the result has the exponent E
				@pre e >= x.e and the upper e - x.e bits of x.f must be zero.
				*/
				static diyfp normalize_to(const diyfp& x, const int target_exponent) noexcept
				{
					const int delta = x.e - target_exponent;

					assert(delta >= 0);
					assert(((x.f << delta) >> delta) == x.f);

					return { x.f << delta, target_exponent };
				}
			};

			struct boundaries
			{
				diyfp w;
				diyfp minus;
				diyfp plus;
			};

			/*!
			Compute the (normalized) diyfp representing the input number 'value' and its
			boundaries.
			@pre value must be finite and positive
			*/
			template <typename FloatType>
			boundaries compute_boundaries(FloatType value)
			{
				assert(std::isfinite(value));
				assert(value > 0);

				// Convert the IEEE representation into a diyfp.
				//
				// If v is denormal:
				//      value = 0.F * 2^(1 - bias) = (          F) * 2^(1 - bias - (p-1))
				// If v is normalized:
				//      value = 1.F * 2^(E - bias) = (2^(p-1) + F) * 2^(E - bias - (p-1))

				static_assert(std::numeric_limits<FloatType>::is_iec559,
					"internal error: dtoa_short requires an IEEE-754 floating-point implementation");

				constexpr int      kPrecision = std::numeric_limits<FloatType>::digits; // = p (includes the hidden bit)
				constexpr int      kBias = std::numeric_limits<FloatType>::max_exponent - 1 + (kPrecision - 1);
				constexpr int      kMinExp = 1 - kBias;
				constexpr std::uint64_t kHiddenBit = std::uint64_t{ 1 } << (kPrecision - 1); // = 2^(p-1)

				using bits_type = typename std::conditional<kPrecision == 24, std::uint32_t, std::uint64_t >::type;

				const std::uint64_t bits = reinterpret_bits<bits_type>(value);
				const std::uint64_t E = bits >> (kPrecision - 1);
				const std::uint64_t F = bits & (kHiddenBit - 1);

				const bool is_denormal = E == 0;
				const diyfp v = is_denormal
					? diyfp(F, kMinExp)
					: diyfp(F + kHiddenBit, static_cast<int>(E) - kBias);

				// Compute the boundaries m- and m+ of the floating-point value
				// v = f * 2^e.
				//
				// Determine v- and v+, the floating-point predecessor and successor if v,
				// respectively.
				//
				//      v- = v - 2^e        if f != 2^(p-1) or e == e_min                (A)
				//         = v - 2^(e-1)    if f == 2^(p-1) and e > e_min                (B)
				//
				//      v+ = v + 2^e
				//
				// Let m- = (v- + v) / 2 and m+ = (v + v+) / 2. All real numbers _strictly_
				// between m- and m+ round to v, regardless of how the input rounding
				// algorithm breaks ties.
				//
				//      ---+-------------+-------------+-------------+-------------+---  (A)
				//         v-            m-            v             m+            v+
				//
				//      -----------------+------+------+-------------+-------------+---  (B)
				//                       v-     m-     v             m+            v+

				const bool lower_boundary_is_closer = F == 0 and E > 1;
				const diyfp m_plus = diyfp(2 * v.f + 1, v.e - 1);
				const diyfp m_minus = lower_boundary_is_closer
					? diyfp(4 * v.f - 1, v.e - 2)  // (B)
					: diyfp(2 * v.f - 1, v.e - 1); // (A)

// Determine the normalized w+ = m+.
				const diyfp w_plus = diyfp::normalize(m_plus);

				// Determine w- = m- such that e_(w-) = e_(w+).
				const diyfp w_minus = diyfp::normalize_to(m_minus, w_plus.e);

				return { diyfp::normalize(v), w_minus, w_plus };
			}

			// Given normalized diyfp w, Grisu needs to find a (normalized) cached
			// power-of-ten c, such that the exponent of the product c * w = f * 2^e lies
			// within a certain range [alpha, gamma] (Definition 3.2 from [1])
			//
			//      alpha <= e = e_c + e_w + q <= gamma
			//
			// or
			//
			//      f_c * f_w * 2^alpha <= f_c 2^(e_c) * f_w 2^(e_w) * 2^q
			//                          <= f_c * f_w * 2^gamma
			//
			// Since c and w are normalized, i.e. 2^(q-1) <= f < 2^q, this implies
			//
			//      2^(q-1) * 2^(q-1) * 2^alpha <= c * w * 2^q < 2^q * 2^q * 2^gamma
			//
			// or
			//
			//      2^(q - 2 + alpha) <= c * w < 2^(q + gamma)
			//
			// The choice of (alpha,gamma) determines the size of the table and the form of
			// the digit generation procedure. Using (alpha,gamma)=(-60,-32) works out well
			// in practice:
			//
			// The idea is to cut the number c * w = f * 2^e into two parts, which can be
			// processed independently: An integral part p1, and a fractional part p2:
			//
			//      f * 2^e = ( (f div 2^-e) * 2^-e + (f mod 2^-e) ) * 2^e
			//              = (f div 2^-e) + (f mod 2^-e) * 2^e
			//              = p1 + p2 * 2^e
			//
			// The conversion of p1 into decimal form requires a series of divisions and
			// modulos by (a power of) 10. These operations are faster for 32-bit than for
			// 64-bit integers, so p1 should ideally fit into a 32-bit integer. This can be
			// achieved by choosing
			//
			//      -e >= 32   or   e <= -32 := gamma
			//
			// In order to convert the fractional part
			//
			//      p2 * 2^e = p2 / 2^-e = d[-1] / 10^1 + d[-2] / 10^2 + ...
			//
			// into decimal form, the fraction is repeatedly multiplied by 10 and the digits
			// d[-i] are extracted in order:
			//
			//      (10 * p2) div 2^-e = d[-1]
			//      (10 * p2) mod 2^-e = d[-2] / 10^1 + ...
			//
			// The multiplication by 10 must not overflow. It is sufficient to choose
			//
			//      10 * p2 < 16 * p2 = 2^4 * p2 <= 2^64.
			//
			// Since p2 = f mod 2^-e < 2^-e,
			//
			//      -e <= 60   or   e >= -60 := alpha

			constexpr int kAlpha = -60;
			constexpr int kGamma = -32;

			struct cached_power // c = f * 2^e ~= 10^k
			{
				std::uint64_t f;
				int e;
				int k;
			};

			/*!
			For a normalized diyfp w = f * 2^e, this function returns a (normalized) cached
			power-of-ten c = f_c * 2^e_c, such that the exponent of the product w * c
			satisfies (Definition 3.2 from [1])
				 alpha <= e_c + e + q <= gamma.
			*/
			inline cached_power get_cached_power_for_binary_exponent(int e)
			{
				// Now
				//
				//      alpha <= e_c + e + q <= gamma                                    (1)
				//      ==> f_c * 2^alpha <= c * 2^e * 2^q
				//
				// and since the c's are normalized, 2^(q-1) <= f_c,
				//
				//      ==> 2^(q - 1 + alpha) <= c * 2^(e + q)
				//      ==> 2^(alpha - e - 1) <= c
				//
				// If c were an exakt power of ten, i.e. c = 10^k, one may determine k as
				//
				//      k = ceil( log_10( 2^(alpha - e - 1) ) )
				//        = ceil( (alpha - e - 1) * log_10(2) )
				//
				// From the paper:
				// "In theory the result of the procedure could be wrong since c is rounded,
				//  and the computation itself is approximated [...]. In practice, however,
				//  this simple function is sufficient."
				//
				// For IEEE double precision floating-point numbers converted into
				// normalized diyfp's w = f * 2^e, with q = 64,
				//
				//      e >= -1022      (min IEEE exponent)
				//           -52        (p - 1)
				//           -52        (p - 1, possibly normalize denormal IEEE numbers)
				//           -11        (normalize the diyfp)
				//         = -1137
				//
				// and
				//
				//      e <= +1023      (max IEEE exponent)
				//           -52        (p - 1)
				//           -11        (normalize the diyfp)
				//         = 960
				//
				// This binary exponent range [-1137,960] results in a decimal exponent
				// range [-307,324]. One does not need to store a cached power for each
				// k in this range. For each such k it suffices to find a cached power
				// such that the exponent of the product lies in [alpha,gamma].
				// This implies that the difference of the decimal exponents of adjacent
				// table entries must be less than or equal to
				//
				//      floor( (gamma - alpha) * log_10(2) ) = 8.
				//
				// (A smaller distance gamma-alpha would require a larger table.)

				// NB:
				// Actually this function returns c, such that -60 <= e_c + e + 64 <= -34.

				constexpr int kCachedPowersMinDecExp = -300;
				constexpr int kCachedPowersDecStep = 8;

				static constexpr std::array<cached_power, 79> kCachedPowers =
				{
					{
						{ 0xAB70FE17C79AC6CA, -1060, -300 },
						{ 0xFF77B1FCBEBCDC4F, -1034, -292 },
						{ 0xBE5691EF416BD60C, -1007, -284 },
						{ 0x8DD01FAD907FFC3C,  -980, -276 },
						{ 0xD3515C2831559A83,  -954, -268 },
						{ 0x9D71AC8FADA6C9B5,  -927, -260 },
						{ 0xEA9C227723EE8BCB,  -901, -252 },
						{ 0xAECC49914078536D,  -874, -244 },
						{ 0x823C12795DB6CE57,  -847, -236 },
						{ 0xC21094364DFB5637,  -821, -228 },
						{ 0x9096EA6F3848984F,  -794, -220 },
						{ 0xD77485CB25823AC7,  -768, -212 },
						{ 0xA086CFCD97BF97F4,  -741, -204 },
						{ 0xEF340A98172AACE5,  -715, -196 },
						{ 0xB23867FB2A35B28E,  -688, -188 },
						{ 0x84C8D4DFD2C63F3B,  -661, -180 },
						{ 0xC5DD44271AD3CDBA,  -635, -172 },
						{ 0x936B9FCEBB25C996,  -608, -164 },
						{ 0xDBAC6C247D62A584,  -582, -156 },
						{ 0xA3AB66580D5FDAF6,  -555, -148 },
						{ 0xF3E2F893DEC3F126,  -529, -140 },
						{ 0xB5B5ADA8AAFF80B8,  -502, -132 },
						{ 0x87625F056C7C4A8B,  -475, -124 },
						{ 0xC9BCFF6034C13053,  -449, -116 },
						{ 0x964E858C91BA2655,  -422, -108 },
						{ 0xDFF9772470297EBD,  -396, -100 },
						{ 0xA6DFBD9FB8E5B88F,  -369,  -92 },
						{ 0xF8A95FCF88747D94,  -343,  -84 },
						{ 0xB94470938FA89BCF,  -316,  -76 },
						{ 0x8A08F0F8BF0F156B,  -289,  -68 },
						{ 0xCDB02555653131B6,  -263,  -60 },
						{ 0x993FE2C6D07B7FAC,  -236,  -52 },
						{ 0xE45C10C42A2B3B06,  -210,  -44 },
						{ 0xAA242499697392D3,  -183,  -36 },
						{ 0xFD87B5F28300CA0E,  -157,  -28 },
						{ 0xBCE5086492111AEB,  -130,  -20 },
						{ 0x8CBCCC096F5088CC,  -103,  -12 },
						{ 0xD1B71758E219652C,   -77,   -4 },
						{ 0x9C40000000000000,   -50,    4 },
						{ 0xE8D4A51000000000,   -24,   12 },
						{ 0xAD78EBC5AC620000,     3,   20 },
						{ 0x813F3978F8940984,    30,   28 },
						{ 0xC097CE7BC90715B3,    56,   36 },
						{ 0x8F7E32CE7BEA5C70,    83,   44 },
						{ 0xD5D238A4ABE98068,   109,   52 },
						{ 0x9F4F2726179A2245,   136,   60 },
						{ 0xED63A231D4C4FB27,   162,   68 },
						{ 0xB0DE65388CC8ADA8,   189,   76 },
						{ 0x83C7088E1AAB65DB,   216,   84 },
						{ 0xC45D1DF942711D9A,   242,   92 },
						{ 0x924D692CA61BE758,   269,  100 },
						{ 0xDA01EE641A708DEA,   295,  108 },
						{ 0xA26DA3999AEF774A,   322,  116 },
						{ 0xF209787BB47D6B85,   348,  124 },
						{ 0xB454E4A179DD1877,   375,  132 },
						{ 0x865B86925B9BC5C2,   402,  140 },
						{ 0xC83553C5C8965D3D,   428,  148 },
						{ 0x952AB45CFA97A0B3,   455,  156 },
						{ 0xDE469FBD99A05FE3,   481,  164 },
						{ 0xA59BC234DB398C25,   508,  172 },
						{ 0xF6C69A72A3989F5C,   534,  180 },
						{ 0xB7DCBF5354E9BECE,   561,  188 },
						{ 0x88FCF317F22241E2,   588,  196 },
						{ 0xCC20CE9BD35C78A5,   614,  204 },
						{ 0x98165AF37B2153DF,   641,  212 },
						{ 0xE2A0B5DC971F303A,   667,  220 },
						{ 0xA8D9D1535CE3B396,   694,  228 },
						{ 0xFB9B7CD9A4A7443C,   720,  236 },
						{ 0xBB764C4CA7A44410,   747,  244 },
						{ 0x8BAB8EEFB6409C1A,   774,  252 },
						{ 0xD01FEF10A657842C,   800,  260 },
						{ 0x9B10A4E5E9913129,   827,  268 },
						{ 0xE7109BFBA19C0C9D,   853,  276 },
						{ 0xAC2820D9623BF429,   880,  284 },
						{ 0x80444B5E7AA7CF85,   907,  292 },
						{ 0xBF21E44003ACDD2D,   933,  300 },
						{ 0x8E679C2F5E44FF8F,   960,  308 },
						{ 0xD433179D9C8CB841,   986,  316 },
						{ 0x9E19DB92B4E31BA9,  1013,  324 },
					}
				};

				// This computation gives exactly the same results for k as
				//      k = ceil((kAlpha - e - 1) * 0.30102999566398114)
				// for |e| <= 1500, but doesn't require floating-point operations.
				// NB: log_10(2) ~= 78913 / 2^18
				assert(e >= -1500);
				assert(e <= 1500);
				const int f = kAlpha - e - 1;
				const int k = (f * 78913) / (1 << 18) + static_cast<int>(f > 0);

				const int index = (-kCachedPowersMinDecExp + k + (kCachedPowersDecStep - 1)) / kCachedPowersDecStep;
				assert(index >= 0);
				assert(static_cast<std::size_t>(index) < kCachedPowers.size());

				const cached_power cached = kCachedPowers[static_cast<std::size_t>(index)];
				assert(kAlpha <= cached.e + e + 64);
				assert(kGamma >= cached.e + e + 64);

				return cached;
			}

			/*!
			For n != 0, returns k, such that pow10 := 10^(k-1) <= n < 10^k.
			For n == 0, returns 1 and sets pow10 := 1.
			*/
			inline int find_largest_pow10(const std::uint32_t n, std::uint32_t& pow10)
			{
				// LCOV_EXCL_START
				if (n >= 1000000000)
				{
					pow10 = 1000000000;
					return 10;
				}
				// LCOV_EXCL_STOP
				else if (n >= 100000000)
				{
					pow10 = 100000000;
					return  9;
				}
				else if (n >= 10000000)
				{
					pow10 = 10000000;
					return  8;
				}
				else if (n >= 1000000)
				{
					pow10 = 1000000;
					return  7;
				}
				else if (n >= 100000)
				{
					pow10 = 100000;
					return  6;
				}
				else if (n >= 10000)
				{
					pow10 = 10000;
					return  5;
				}
				else if (n >= 1000)
				{
					pow10 = 1000;
					return  4;
				}
				else if (n >= 100)
				{
					pow10 = 100;
					return  3;
				}
				else if (n >= 10)
				{
					pow10 = 10;
					return  2;
				}
				else
				{
					pow10 = 1;
					return 1;
				}
			}

			inline void grisu2_round(char* buf, int len, std::uint64_t dist, std::uint64_t delta,
				std::uint64_t rest, std::uint64_t ten_k)
			{
				assert(len >= 1);
				assert(dist <= delta);
				assert(rest <= delta);
				assert(ten_k > 0);

				//               <--------------------------- delta ---->
				//                                  <---- dist --------->
				// --------------[------------------+-------------------]--------------
				//               M-                 w                   M+
				//
				//                                  ten_k
				//                                <------>
				//                                       <---- rest ---->
				// --------------[------------------+----+--------------]--------------
				//                                  w    V
				//                                       = buf * 10^k
				//
				// ten_k represents a unit-in-the-last-place in the decimal representation
				// stored in buf.
				// Decrement buf by ten_k while this takes buf closer to w.

				// The tests are written in this order to avoid overflow in unsigned
				// integer arithmetic.

				while (rest < dist
					and delta - rest >= ten_k
					and (rest + ten_k < dist or dist - rest > rest + ten_k - dist))
				{
					assert(buf[len - 1] != '0');
					buf[len - 1]--;
					rest += ten_k;
				}
			}

			/*!
			Generates V = buffer * 10^decimal_exponent, such that M- <= V <= M+.
			M- and M+ must be normalized and share the same exponent -60 <= e <= -32.
			*/
			inline void grisu2_digit_gen(char* buffer, int& length, int& decimal_exponent,
				diyfp M_minus, diyfp w, diyfp M_plus)
			{
				static_assert(kAlpha >= -60, "internal error");
				static_assert(kGamma <= -32, "internal error");

				// Generates the digits (and the exponent) of a decimal floating-point
				// number V = buffer * 10^decimal_exponent in the range [M-, M+]. The diyfp's
				// w, M- and M+ share the same exponent e, which satisfies alpha <= e <= gamma.
				//
				//               <--------------------------- delta ---->
				//                                  <---- dist --------->
				// --------------[------------------+-------------------]--------------
				//               M-                 w                   M+
				//
				// Grisu2 generates the digits of M+ from left to right and stops as soon as
				// V is in [M-,M+].

				assert(M_plus.e >= kAlpha);
				assert(M_plus.e <= kGamma);

				std::uint64_t delta = diyfp::sub(M_plus, M_minus).f; // (significand of (M+ - M-), implicit exponent is e)
				std::uint64_t dist = diyfp::sub(M_plus, w).f; // (significand of (M+ - w ), implicit exponent is e)

				// Split M+ = f * 2^e into two parts p1 and p2 (note: e < 0):
				//
				//      M+ = f * 2^e
				//         = ((f div 2^-e) * 2^-e + (f mod 2^-e)) * 2^e
				//         = ((p1        ) * 2^-e + (p2        )) * 2^e
				//         = p1 + p2 * 2^e

				const diyfp one(std::uint64_t{ 1 } << -M_plus.e, M_plus.e);

				auto p1 = static_cast<std::uint32_t>(M_plus.f >> -one.e); // p1 = f div 2^-e (Since -e >= 32, p1 fits into a 32-bit int.)
				std::uint64_t p2 = M_plus.f & (one.f - 1);                    // p2 = f mod 2^-e

				// 1)
				//
				// Generate the digits of the integral part p1 = d[n-1]...d[1]d[0]

				assert(p1 > 0);

				std::uint32_t pow10;
				const int k = find_largest_pow10(p1, pow10);

				//      10^(k-1) <= p1 < 10^k, pow10 = 10^(k-1)
				//
				//      p1 = (p1 div 10^(k-1)) * 10^(k-1) + (p1 mod 10^(k-1))
				//         = (d[k-1]         ) * 10^(k-1) + (p1 mod 10^(k-1))
				//
				//      M+ = p1                                             + p2 * 2^e
				//         = d[k-1] * 10^(k-1) + (p1 mod 10^(k-1))          + p2 * 2^e
				//         = d[k-1] * 10^(k-1) + ((p1 mod 10^(k-1)) * 2^-e + p2) * 2^e
				//         = d[k-1] * 10^(k-1) + (                         rest) * 2^e
				//
				// Now generate the digits d[n] of p1 from left to right (n = k-1,...,0)
				//
				//      p1 = d[k-1]...d[n] * 10^n + d[n-1]...d[0]
				//
				// but stop as soon as
				//
				//      rest * 2^e = (d[n-1]...d[0] * 2^-e + p2) * 2^e <= delta * 2^e

				int n = k;
				while (n > 0)
				{
					// Invariants:
					//      M+ = buffer * 10^n + (p1 + p2 * 2^e)    (buffer = 0 for n = k)
					//      pow10 = 10^(n-1) <= p1 < 10^n
					//
					const std::uint32_t d = p1 / pow10;  // d = p1 div 10^(n-1)
					const std::uint32_t r = p1 % pow10;  // r = p1 mod 10^(n-1)
					//
					//      M+ = buffer * 10^n + (d * 10^(n-1) + r) + p2 * 2^e
					//         = (buffer * 10 + d) * 10^(n-1) + (r + p2 * 2^e)
					//
					assert(d <= 9);
					buffer[length++] = static_cast<char>('0' + d); // buffer := buffer * 10 + d
					//
					//      M+ = buffer * 10^(n-1) + (r + p2 * 2^e)
					//
					p1 = r;
					n--;
					//
					//      M+ = buffer * 10^n + (p1 + p2 * 2^e)
					//      pow10 = 10^n
					//

					// Now check if enough digits have been generated.
					// Compute
					//
					//      p1 + p2 * 2^e = (p1 * 2^-e + p2) * 2^e = rest * 2^e
					//
					// Note:
					// Since rest and delta share the same exponent e, it suffices to
					// compare the significands.
					const std::uint64_t rest = (std::uint64_t{ p1 } << -one.e) + p2;
					if (rest <= delta)
					{
						// V = buffer * 10^n, with M- <= V <= M+.

						decimal_exponent += n;

						// We may now just stop. But instead look if the buffer could be
						// decremented to bring V closer to w.
						//
						// pow10 = 10^n is now 1 ulp in the decimal representation V.
						// The rounding procedure works with diyfp's with an implicit
						// exponent of e.
						//
						//      10^n = (10^n * 2^-e) * 2^e = ulp * 2^e
						//
						const std::uint64_t ten_n = std::uint64_t{ pow10 } << -one.e;
						grisu2_round(buffer, length, dist, delta, rest, ten_n);

						return;
					}

					pow10 /= 10;
					//
					//      pow10 = 10^(n-1) <= p1 < 10^n
					// Invariants restored.
				}

				// 2)
				//
				// The digits of the integral part have been generated:
				//
				//      M+ = d[k-1]...d[1]d[0] + p2 * 2^e
				//         = buffer            + p2 * 2^e
				//
				// Now generate the digits of the fractional part p2 * 2^e.
				//
				// Note:
				// No decimal point is generated: the exponent is adjusted instead.
				//
				// p2 actually represents the fraction
				//
				//      p2 * 2^e
				//          = p2 / 2^-e
				//          = d[-1] / 10^1 + d[-2] / 10^2 + ...
				//
				// Now generate the digits d[-m] of p1 from left to right (m = 1,2,...)
				//
				//      p2 * 2^e = d[-1]d[-2]...d[-m] * 10^-m
				//                      + 10^-m * (d[-m-1] / 10^1 + d[-m-2] / 10^2 + ...)
				//
				// using
				//
				//      10^m * p2 = ((10^m * p2) div 2^-e) * 2^-e + ((10^m * p2) mod 2^-e)
				//                = (                   d) * 2^-e + (                   r)
				//
				// or
				//      10^m * p2 * 2^e = d + r * 2^e
				//
				// i.e.
				//
				//      M+ = buffer + p2 * 2^e
				//         = buffer + 10^-m * (d + r * 2^e)
				//         = (buffer * 10^m + d) * 10^-m + 10^-m * r * 2^e
				//
				// and stop as soon as 10^-m * r * 2^e <= delta * 2^e

				assert(p2 > delta);

				int m = 0;
				for (;;)
				{
					// Invariant:
					//      M+ = buffer * 10^-m + 10^-m * (d[-m-1] / 10 + d[-m-2] / 10^2 + ...) * 2^e
					//         = buffer * 10^-m + 10^-m * (p2                                 ) * 2^e
					//         = buffer * 10^-m + 10^-m * (1/10 * (10 * p2)                   ) * 2^e
					//         = buffer * 10^-m + 10^-m * (1/10 * ((10*p2 div 2^-e) * 2^-e + (10*p2 mod 2^-e)) * 2^e
					//
					assert(p2 <= (std::numeric_limits<std::uint64_t>::max)() / 10);
					p2 *= 10;
					const std::uint64_t d = p2 >> -one.e;     // d = (10 * p2) div 2^-e
					const std::uint64_t r = p2 & (one.f - 1); // r = (10 * p2) mod 2^-e
					//
					//      M+ = buffer * 10^-m + 10^-m * (1/10 * (d * 2^-e + r) * 2^e
					//         = buffer * 10^-m + 10^-m * (1/10 * (d + r * 2^e))
					//         = (buffer * 10 + d) * 10^(-m-1) + 10^(-m-1) * r * 2^e
					//
					assert(d <= 9);
					buffer[length++] = static_cast<char>('0' + d); // buffer := buffer * 10 + d
					//
					//      M+ = buffer * 10^(-m-1) + 10^(-m-1) * r * 2^e
					//
					p2 = r;
					m++;
					//
					//      M+ = buffer * 10^-m + 10^-m * p2 * 2^e
					// Invariant restored.

					// Check if enough digits have been generated.
					//
					//      10^-m * p2 * 2^e <= delta * 2^e
					//              p2 * 2^e <= 10^m * delta * 2^e
					//                    p2 <= 10^m * delta
					delta *= 10;
					dist *= 10;
					if (p2 <= delta)
					{
						break;
					}
				}

				// V = buffer * 10^-m, with M- <= V <= M+.

				decimal_exponent -= m;

				// 1 ulp in the decimal representation is now 10^-m.
				// Since delta and dist are now scaled by 10^m, we need to do the
				// same with ulp in order to keep the units in sync.
				//
				//      10^m * 10^-m = 1 = 2^-e * 2^e = ten_m * 2^e
				//
				const std::uint64_t ten_m = one.f;
				grisu2_round(buffer, length, dist, delta, p2, ten_m);

				// By construction this algorithm generates the shortest possible decimal
				// number (Loitsch, Theorem 6.2) which rounds back to w.
				// For an input number of precision p, at least
				//
				//      N = 1 + ceil(p * log_10(2))
				//
				// decimal digits are sufficient to identify all binary floating-point
				// numbers (Matula, "In-and-Out conversions").
				// This implies that the algorithm does not produce more than N decimal
				// digits.
				//
				//      N = 17 for p = 53 (IEEE double precision)
				//      N = 9  for p = 24 (IEEE single precision)
			}

			/*!
			v = buf * 10^decimal_exponent
			len is the length of the buffer (number of decimal digits)
			The buffer must be large enough, i.e. >= max_digits10.
			*/
			JSON_HEDLEY_NON_NULL(1)
				inline void grisu2(char* buf, int& len, int& decimal_exponent,
					diyfp m_minus, diyfp v, diyfp m_plus)
			{
				assert(m_plus.e == m_minus.e);
				assert(m_plus.e == v.e);

				//  --------(-----------------------+-----------------------)--------    (A)
				//          m-                      v                       m+
				//
				//  --------------------(-----------+-----------------------)--------    (B)
				//                      m-          v                       m+
				//
				// First scale v (and m- and m+) such that the exponent is in the range
				// [alpha, gamma].

				const cached_power cached = get_cached_power_for_binary_exponent(m_plus.e);

				const diyfp c_minus_k(cached.f, cached.e); // = c ~= 10^-k

				// The exponent of the products is = v.e + c_minus_k.e + q and is in the range [alpha,gamma]
				const diyfp w = diyfp::mul(v, c_minus_k);
				const diyfp w_minus = diyfp::mul(m_minus, c_minus_k);
				const diyfp w_plus = diyfp::mul(m_plus, c_minus_k);

				//  ----(---+---)---------------(---+---)---------------(---+---)----
				//          w-                      w                       w+
				//          = c*m-                  = c*v                   = c*m+
				//
				// diyfp::mul rounds its result and c_minus_k is approximated too. w, w- and
				// w+ are now off by a small amount.
				// In fact:
				//
				//      w - v * 10^k < 1 ulp
				//
				// To account for this inaccuracy, add resp. subtract 1 ulp.
				//
				//  --------+---[---------------(---+---)---------------]---+--------
				//          w-  M-                  w                   M+  w+
				//
				// Now any number in [M-, M+] (bounds included) will round to w when input,
				// regardless of how the input rounding algorithm breaks ties.
				//
				// And digit_gen generates the shortest possible such number in [M-, M+].
				// Note that this does not mean that Grisu2 always generates the shortest
				// possible number in the interval (m-, m+).
				const diyfp M_minus(w_minus.f + 1, w_minus.e);
				const diyfp M_plus(w_plus.f - 1, w_plus.e);

				decimal_exponent = -cached.k; // = -(-k) = k

				grisu2_digit_gen(buf, len, decimal_exponent, M_minus, w, M_plus);
			}

			/*!
			v = buf * 10^decimal_exponent
			len is the length of the buffer (number of decimal digits)
			The buffer must be large enough, i.e. >= max_digits10.
			*/
			template <typename FloatType>
			JSON_HEDLEY_NON_NULL(1)
				void grisu2(char* buf, int& len, int& decimal_exponent, FloatType value)
			{
				static_assert(diyfp::kPrecision >= std::numeric_limits<FloatType>::digits + 3,
					"internal error: not enough precision");

				assert(std::isfinite(value));
				assert(value > 0);

				// If the neighbors (and boundaries) of 'value' are always computed for double-precision
				// numbers, all float's can be recovered using strtod (and strtof). However, the resulting
				// decimal representations are not exactly "short".
				//
				// The documentation for 'std::to_chars' (https://en.cppreference.com/w/cpp/utility/to_chars)
				// says "value is converted to a string as if by std::sprintf in the default ("C") locale"
				// and since sprintf promotes float's to double's, I think this is exactly what 'std::to_chars'
				// does.
				// On the other hand, the documentation for 'std::to_chars' requires that "parsing the
				// representation using the corresponding std::from_chars function recovers value exactly". That
				// indicates that single precision floating-point numbers should be recovered using
				// 'std::strtof'.
				//
				// NB: If the neighbors are computed for single-precision numbers, there is a single float
				//     (7.0385307e-26f) which can't be recovered using strtod. The resulting double precision
				//     value is off by 1 ulp.
#if 0
				const boundaries w = compute_boundaries(static_cast<double>(value));
#else
				const boundaries w = compute_boundaries(value);
#endif

				grisu2(buf, len, decimal_exponent, w.minus, w.w, w.plus);
			}

			/*!
			@brief appends a decimal representation of e to buf
			@return a pointer to the element following the exponent.
			@pre -1000 < e < 1000
			*/
			JSON_HEDLEY_NON_NULL(1)
				JSON_HEDLEY_RETURNS_NON_NULL
				inline char* append_exponent(char* buf, int e)
			{
				assert(e > -1000);
				assert(e < 1000);

				if (e < 0)
				{
					e = -e;
					*buf++ = '-';
				}
				else
				{
					*buf++ = '+';
				}

				auto k = static_cast<std::uint32_t>(e);
				if (k < 10)
				{
					// Always print at least two digits in the exponent.
					// This is for compatibility with printf("%g").
					*buf++ = '0';
					*buf++ = static_cast<char>('0' + k);
				}
				else if (k < 100)
				{
					*buf++ = static_cast<char>('0' + k / 10);
					k %= 10;
					*buf++ = static_cast<char>('0' + k);
				}
				else
				{
					*buf++ = static_cast<char>('0' + k / 100);
					k %= 100;
					*buf++ = static_cast<char>('0' + k / 10);
					k %= 10;
					*buf++ = static_cast<char>('0' + k);
				}

				return buf;
			}

			/*!
			@brief prettify v = buf * 10^decimal_exponent
			If v is in the range [10^min_exp, 10^max_exp) it will be printed in fixed-point
			notation. Otherwise it will be printed in exponential notation.
			@pre min_exp < 0
			@pre max_exp > 0
			*/
			JSON_HEDLEY_NON_NULL(1)
				JSON_HEDLEY_RETURNS_NON_NULL
				inline char* format_buffer(char* buf, int len, int decimal_exponent,
					int min_exp, int max_exp)
			{
				assert(min_exp < 0);
				assert(max_exp > 0);

				const int k = len;
				const int n = len + decimal_exponent;

				// v = buf * 10^(n-k)
				// k is the length of the buffer (number of decimal digits)
				// n is the position of the decimal point relative to the start of the buffer.

				if (k <= n and n <= max_exp)
				{
					// digits[000]
					// len <= max_exp + 2

					std::memset(buf + k, '0', static_cast<size_t>(n - k));
					// Make it look like a floating-point number (#362, #378)
					buf[n + 0] = '.';
					buf[n + 1] = '0';
					return buf + (n + 2);
				}

				if (0 < n and n <= max_exp)
				{
					// dig.its
					// len <= max_digits10 + 1

					assert(k > n);

					std::memmove(buf + (n + 1), buf + n, static_cast<size_t>(k - n));
					buf[n] = '.';
					return buf + (k + 1);
				}

				if (min_exp < n and n <= 0)
				{
					// 0.[000]digits
					// len <= 2 + (-min_exp - 1) + max_digits10

					std::memmove(buf + (2 + -n), buf, static_cast<size_t>(k));
					buf[0] = '0';
					buf[1] = '.';
					std::memset(buf + 2, '0', static_cast<size_t>(-n));
					return buf + (2 + (-n) + k);
				}

				if (k == 1)
				{
					// dE+123
					// len <= 1 + 5

					buf += 1;
				}
				else
				{
					// d.igitsE+123
					// len <= max_digits10 + 1 + 5

					std::memmove(buf + 2, buf + 1, static_cast<size_t>(k - 1));
					buf[1] = '.';
					buf += 1 + k;
				}

				*buf++ = 'e';
				return append_exponent(buf, n - 1);
			}

		} // namespace dtoa_impl

		/*!
		@brief generates a decimal representation of the floating-point number value in [first, last).
		The format of the resulting decimal representation is similar to printf's %g
		format. Returns an iterator pointing past-the-end of the decimal representation.
		@note The input number must be finite, i.e. NaN's and Inf's are not supported.
		@note The buffer must be large enough.
		@note The result is NOT null-terminated.
		*/
		template <typename FloatType>
		JSON_HEDLEY_NON_NULL(1, 2)
			JSON_HEDLEY_RETURNS_NON_NULL
			char* to_chars(char* first, const char* last, FloatType value)
		{
			static_cast<void>(last); // maybe unused - fix warning
			assert(std::isfinite(value));

			// Use signbit(value) instead of (value < 0) since signbit works for -0.
			if (std::signbit(value))
			{
				value = -value;
				*first++ = '-';
			}

			if (value == 0) // +-0
			{
				*first++ = '0';
				// Make it look like a floating-point number (#362, #378)
				*first++ = '.';
				*first++ = '0';
				return first;
			}

			assert(last - first >= std::numeric_limits<FloatType>::max_digits10);

			// Compute v = buffer * 10^decimal_exponent.
			// The decimal digits are stored in the buffer, which needs to be interpreted
			// as an unsigned decimal integer.
			// len is the length of the buffer, i.e. the number of decimal digits.
			int len = 0;
			int decimal_exponent = 0;
			dtoa_impl::grisu2(first, len, decimal_exponent, value);

			assert(len <= std::numeric_limits<FloatType>::max_digits10);

			// Format the buffer like printf("%.*g", prec, value)
			constexpr int kMinExp = -4;
			// Use digits10 here to increase compatibility with version 2.
			constexpr int kMaxExp = std::numeric_limits<FloatType>::digits10;

			assert(last - first >= kMaxExp + 2);
			assert(last - first >= 2 + (-kMinExp - 1) + std::numeric_limits<FloatType>::max_digits10);
			assert(last - first >= std::numeric_limits<FloatType>::max_digits10 + 6);

			return dtoa_impl::format_buffer(first, len, decimal_exponent, kMinExp, kMaxExp);
		}

	} // namespace detail
} // namespace nlohmann

// #include <nlohmann/detail/exceptions.hpp>

// #include <nlohmann/detail/macro_scope.hpp>

// #include <nlohmann/detail/meta/cpp_future.hpp>

// #include <nlohmann/detail/output/binary_writer.hpp>

// #include <nlohmann/detail/output/output_adapters.hpp>

// #include <nlohmann/detail/value_t.hpp>


namespace nlohmann
{
	namespace detail
	{
		///////////////////
		// serialization //
		///////////////////

		/// how to treat decoding errors
		enum class error_handler_t
		{
			strict,  ///< throw a type_error exception in case of invalid UTF-8
			replace, ///< replace invalid UTF-8 sequences with U+FFFD
			ignore   ///< ignore invalid UTF-8 sequences
		};

		template<typename BasicJsonType>
		class serializer
		{
			using string_t = typename BasicJsonType::string_t;
			using number_float_t = typename BasicJsonType::number_float_t;
			using number_integer_t = typename BasicJsonType::number_integer_t;
			using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
			static constexpr std::uint8_t UTF8_ACCEPT = 0;
			static constexpr std::uint8_t UTF8_REJECT = 1;

		public:
			/*!
			@param[in] s  output stream to serialize to
			@param[in] ichar  indentation character to use
			@param[in] error_handler_  how to react on decoding errors
			*/
			serializer(output_adapter_t<char> s, const char ichar,
				error_handler_t error_handler_ = error_handler_t::strict)
				: o(std::move(s))
				, loc(std::localeconv())
				, thousands_sep(loc->thousands_sep == nullptr ? '\0' : *(loc->thousands_sep))
				, decimal_point(loc->decimal_point == nullptr ? '\0' : *(loc->decimal_point))
				, indent_char(ichar)
				, indent_string(512, indent_char)
				, error_handler(error_handler_)
			{}

			// delete because of pointer members
			serializer(const serializer&) = delete;
			serializer& operator=(const serializer&) = delete;
			serializer(serializer&&) = delete;
			serializer& operator=(serializer&&) = delete;
			~serializer() = default;

			/*!
			@brief internal implementation of the serialization function
			This function is called by the public member function dump and organizes
			the serialization internally. The indentation level is propagated as
			additional parameter. In case of arrays and objects, the function is
			called recursively.
			- strings and object keys are escaped using `escape_string()`
			- integer numbers are converted implicitly via `operator<<`
			- floating-point numbers are converted to a string using `"%g"` format
			@param[in] val             value to serialize
			@param[in] pretty_print    whether the output shall be pretty-printed
			@param[in] indent_step     the indent level
			@param[in] current_indent  the current indent level (only used internally)
			*/
			void dump(const BasicJsonType& val, const bool pretty_print,
				const bool ensure_ascii,
				const unsigned int indent_step,
				const unsigned int current_indent = 0)
			{
				switch (val.m_type)
				{
				case value_t::object:
				{
					if (val.m_value.object->empty())
					{
						o->write_characters("{}", 2);
						return;
					}

					if (pretty_print)
					{
						o->write_characters("{\n", 2);

						// variable to hold indentation for recursive calls
						const auto new_indent = current_indent + indent_step;
						if (JSON_HEDLEY_UNLIKELY(indent_string.size() < new_indent))
						{
							indent_string.resize(indent_string.size() * 2, ' ');
						}

						// first n-1 elements
						auto i = val.m_value.object->cbegin();
						for (std::size_t cnt = 0; cnt < val.m_value.object->size() - 1; ++cnt, ++i)
						{
							o->write_characters(indent_string.c_str(), new_indent);
							o->write_character('\"');
							dump_escaped(i->first, ensure_ascii);
							o->write_characters("\": ", 3);
							dump(i->second, true, ensure_ascii, indent_step, new_indent);
							o->write_characters(",\n", 2);
						}

						// last element
						assert(i != val.m_value.object->cend());
						assert(std::next(i) == val.m_value.object->cend());
						o->write_characters(indent_string.c_str(), new_indent);
						o->write_character('\"');
						dump_escaped(i->first, ensure_ascii);
						o->write_characters("\": ", 3);
						dump(i->second, true, ensure_ascii, indent_step, new_indent);

						o->write_character('\n');
						o->write_characters(indent_string.c_str(), current_indent);
						o->write_character('}');
					}
					else
					{
						o->write_character('{');

						// first n-1 elements
						auto i = val.m_value.object->cbegin();
						for (std::size_t cnt = 0; cnt < val.m_value.object->size() - 1; ++cnt, ++i)
						{
							o->write_character('\"');
							dump_escaped(i->first, ensure_ascii);
							o->write_characters("\":", 2);
							dump(i->second, false, ensure_ascii, indent_step, current_indent);
							o->write_character(',');
						}

						// last element
						assert(i != val.m_value.object->cend());
						assert(std::next(i) == val.m_value.object->cend());
						o->write_character('\"');
						dump_escaped(i->first, ensure_ascii);
						o->write_characters("\":", 2);
						dump(i->second, false, ensure_ascii, indent_step, current_indent);

						o->write_character('}');
					}

					return;
				}

				case value_t::array:
				{
					if (val.m_value.array->empty())
					{
						o->write_characters("[]", 2);
						return;
					}

					if (pretty_print)
					{
						o->write_characters("[\n", 2);

						// variable to hold indentation for recursive calls
						const auto new_indent = current_indent + indent_step;
						if (JSON_HEDLEY_UNLIKELY(indent_string.size() < new_indent))
						{
							indent_string.resize(indent_string.size() * 2, ' ');
						}

						// first n-1 elements
						for (auto i = val.m_value.array->cbegin();
							i != val.m_value.array->cend() - 1; ++i)
						{
							o->write_characters(indent_string.c_str(), new_indent);
							dump(*i, true, ensure_ascii, indent_step, new_indent);
							o->write_characters(",\n", 2);
						}

						// last element
						assert(not val.m_value.array->empty());
						o->write_characters(indent_string.c_str(), new_indent);
						dump(val.m_value.array->back(), true, ensure_ascii, indent_step, new_indent);

						o->write_character('\n');
						o->write_characters(indent_string.c_str(), current_indent);
						o->write_character(']');
					}
					else
					{
						o->write_character('[');

						// first n-1 elements
						for (auto i = val.m_value.array->cbegin();
							i != val.m_value.array->cend() - 1; ++i)
						{
							dump(*i, false, ensure_ascii, indent_step, current_indent);
							o->write_character(',');
						}

						// last element
						assert(not val.m_value.array->empty());
						dump(val.m_value.array->back(), false, ensure_ascii, indent_step, current_indent);

						o->write_character(']');
					}

					return;
				}

				case value_t::string:
				{
					o->write_character('\"');
					dump_escaped(*val.m_value.string, ensure_ascii);
					o->write_character('\"');
					return;
				}

				case value_t::boolean:
				{
					if (val.m_value.boolean)
					{
						o->write_characters("true", 4);
					}
					else
					{
						o->write_characters("false", 5);
					}
					return;
				}

				case value_t::number_integer:
				{
					dump_integer(val.m_value.number_integer);
					return;
				}

				case value_t::number_unsigned:
				{
					dump_integer(val.m_value.number_unsigned);
					return;
				}

				case value_t::number_float:
				{
					dump_float(val.m_value.number_float);
					return;
				}

				case value_t::discarded:
				{
					o->write_characters("<discarded>", 11);
					return;
				}

				case value_t::null:
				{
					o->write_characters("null", 4);
					return;
				}

				default:            // LCOV_EXCL_LINE
					assert(false);  // LCOV_EXCL_LINE
				}
			}

		private:
			/*!
			@brief dump escaped string
			Escape a string by replacing certain special characters by a sequence of an
			escape character (backslash) and another character and other control
			characters by a sequence of "\u" followed by a four-digit hex
			representation. The escaped string is written to output stream @a o.
			@param[in] s  the string to escape
			@param[in] ensure_ascii  whether to escape non-ASCII characters with
									 \uXXXX sequences
			@complexity Linear in the length of string @a s.
			*/
			void dump_escaped(const string_t& s, const bool ensure_ascii)
			{
				std::uint32_t codepoint;
				std::uint8_t state = UTF8_ACCEPT;
				std::size_t bytes = 0;  // number of bytes written to string_buffer

				// number of bytes written at the point of the last valid byte
				std::size_t bytes_after_last_accept = 0;
				std::size_t undumped_chars = 0;

				for (std::size_t i = 0; i < s.size(); ++i)
				{
					const auto byte = static_cast<uint8_t>(s[i]);

					switch (decode(state, codepoint, byte))
					{
					case UTF8_ACCEPT:  // decode found a new code point
					{
						switch (codepoint)
						{
						case 0x08: // backspace
						{
							string_buffer[bytes++] = '\\';
							string_buffer[bytes++] = 'b';
							break;
						}

						case 0x09: // horizontal tab
						{
							string_buffer[bytes++] = '\\';
							string_buffer[bytes++] = 't';
							break;
						}

						case 0x0A: // newline
						{
							string_buffer[bytes++] = '\\';
							string_buffer[bytes++] = 'n';
							break;
						}

						case 0x0C: // formfeed
						{
							string_buffer[bytes++] = '\\';
							string_buffer[bytes++] = 'f';
							break;
						}

						case 0x0D: // carriage return
						{
							string_buffer[bytes++] = '\\';
							string_buffer[bytes++] = 'r';
							break;
						}

						case 0x22: // quotation mark
						{
							string_buffer[bytes++] = '\\';
							string_buffer[bytes++] = '\"';
							break;
						}

						case 0x5C: // reverse solidus
						{
							string_buffer[bytes++] = '\\';
							string_buffer[bytes++] = '\\';
							break;
						}

						default:
						{
							// escape control characters (0x00..0x1F) or, if
							// ensure_ascii parameter is used, non-ASCII characters
							if ((codepoint <= 0x1F) or (ensure_ascii and (codepoint >= 0x7F)))
							{
								if (codepoint <= 0xFFFF)
								{
									(std::snprintf)(string_buffer.data() + bytes, 7, "\\u%04x",
										static_cast<std::uint16_t>(codepoint));
									bytes += 6;
								}
								else
								{
									(std::snprintf)(string_buffer.data() + bytes, 13, "\\u%04x\\u%04x",
										static_cast<std::uint16_t>(0xD7C0u + (codepoint >> 10u)),
										static_cast<std::uint16_t>(0xDC00u + (codepoint & 0x3FFu)));
									bytes += 12;
								}
							}
							else
							{
								// copy byte to buffer (all previous bytes
								// been copied have in default case above)
								string_buffer[bytes++] = s[i];
							}
							break;
						}
						}

						// write buffer and reset index; there must be 13 bytes
						// left, as this is the maximal number of bytes to be
						// written ("\uxxxx\uxxxx\0") for one code point
						if (string_buffer.size() - bytes < 13)
						{
							o->write_characters(string_buffer.data(), bytes);
							bytes = 0;
						}

						// remember the byte position of this accept
						bytes_after_last_accept = bytes;
						undumped_chars = 0;
						break;
					}

					case UTF8_REJECT:  // decode found invalid UTF-8 byte
					{
						switch (error_handler)
						{
						case error_handler_t::strict:
						{
							std::string sn(3, '\0');
							(std::snprintf)(&sn[0], sn.size(), "%.2X", byte);
							JSON_THROW(type_error::create(316, "invalid UTF-8 byte at index " + std::to_string(i) + ": 0x" + sn));
						}

						case error_handler_t::ignore:
						case error_handler_t::replace:
						{
							// in case we saw this character the first time, we
							// would like to read it again, because the byte
							// may be OK for itself, but just not OK for the
							// previous sequence
							if (undumped_chars > 0)
							{
								--i;
							}

							// reset length buffer to the last accepted index;
							// thus removing/ignoring the invalid characters
							bytes = bytes_after_last_accept;

							if (error_handler == error_handler_t::replace)
							{
								// add a replacement character
								if (ensure_ascii)
								{
									string_buffer[bytes++] = '\\';
									string_buffer[bytes++] = 'u';
									string_buffer[bytes++] = 'f';
									string_buffer[bytes++] = 'f';
									string_buffer[bytes++] = 'f';
									string_buffer[bytes++] = 'd';
								}
								else
								{
									string_buffer[bytes++] = detail::binary_writer<BasicJsonType, char>::to_char_type('\xEF');
									string_buffer[bytes++] = detail::binary_writer<BasicJsonType, char>::to_char_type('\xBF');
									string_buffer[bytes++] = detail::binary_writer<BasicJsonType, char>::to_char_type('\xBD');
								}

								// write buffer and reset index; there must be 13 bytes
								// left, as this is the maximal number of bytes to be
								// written ("\uxxxx\uxxxx\0") for one code point
								if (string_buffer.size() - bytes < 13)
								{
									o->write_characters(string_buffer.data(), bytes);
									bytes = 0;
								}

								bytes_after_last_accept = bytes;
							}

							undumped_chars = 0;

							// continue processing the string
							state = UTF8_ACCEPT;
							break;
						}

						default:            // LCOV_EXCL_LINE
							assert(false);  // LCOV_EXCL_LINE
						}
						break;
					}

					default:  // decode found yet incomplete multi-byte code point
					{
						if (not ensure_ascii)
						{
							// code point will not be escaped - copy byte to buffer
							string_buffer[bytes++] = s[i];
						}
						++undumped_chars;
						break;
					}
					}
				}

				// we finished processing the string
				if (JSON_HEDLEY_LIKELY(state == UTF8_ACCEPT))
				{
					// write buffer
					if (bytes > 0)
					{
						o->write_characters(string_buffer.data(), bytes);
					}
				}
				else
				{
					// we finish reading, but do not accept: string was incomplete
					switch (error_handler)
					{
					case error_handler_t::strict:
					{
						std::string sn(3, '\0');
						(std::snprintf)(&sn[0], sn.size(), "%.2X", static_cast<std::uint8_t>(s.back()));
						JSON_THROW(type_error::create(316, "incomplete UTF-8 string; last byte: 0x" + sn));
					}

					case error_handler_t::ignore:
					{
						// write all accepted bytes
						o->write_characters(string_buffer.data(), bytes_after_last_accept);
						break;
					}

					case error_handler_t::replace:
					{
						// write all accepted bytes
						o->write_characters(string_buffer.data(), bytes_after_last_accept);
						// add a replacement character
						if (ensure_ascii)
						{
							o->write_characters("\\ufffd", 6);
						}
						else
						{
							o->write_characters("\xEF\xBF\xBD", 3);
						}
						break;
					}

					default:            // LCOV_EXCL_LINE
						assert(false);  // LCOV_EXCL_LINE
					}
				}
			}

			/*!
			@brief count digits
			Count the number of decimal (base 10) digits for an input unsigned integer.
			@param[in] x  unsigned integer number to count its digits
			@return    number of decimal digits
			*/
			inline unsigned int count_digits(number_unsigned_t x) noexcept
			{
				unsigned int n_digits = 1;
				for (;;)
				{
					if (x < 10)
					{
						return n_digits;
					}
					if (x < 100)
					{
						return n_digits + 1;
					}
					if (x < 1000)
					{
						return n_digits + 2;
					}
					if (x < 10000)
					{
						return n_digits + 3;
					}
					x = x / 10000u;
					n_digits += 4;
				}
			}

			/*!
			@brief dump an integer
			Dump a given integer to output stream @a o. Works internally with
			@a number_buffer.
			@param[in] x  integer number (signed or unsigned) to dump
			@tparam NumberType either @a number_integer_t or @a number_unsigned_t
			*/
			template<typename NumberType, detail::enable_if_t<
				std::is_same<NumberType, number_unsigned_t>::value or
				std::is_same<NumberType, number_integer_t>::value,
				int> = 0>
				void dump_integer(NumberType x)
			{
				static constexpr std::array<std::array<char, 2>, 100> digits_to_99
				{
					{
						{{'0', '0'}}, {{'0', '1'}}, {{'0', '2'}}, {{'0', '3'}}, {{'0', '4'}}, {{'0', '5'}}, {{'0', '6'}}, {{'0', '7'}}, {{'0', '8'}}, {{'0', '9'}},
						{{'1', '0'}}, {{'1', '1'}}, {{'1', '2'}}, {{'1', '3'}}, {{'1', '4'}}, {{'1', '5'}}, {{'1', '6'}}, {{'1', '7'}}, {{'1', '8'}}, {{'1', '9'}},
						{{'2', '0'}}, {{'2', '1'}}, {{'2', '2'}}, {{'2', '3'}}, {{'2', '4'}}, {{'2', '5'}}, {{'2', '6'}}, {{'2', '7'}}, {{'2', '8'}}, {{'2', '9'}},
						{{'3', '0'}}, {{'3', '1'}}, {{'3', '2'}}, {{'3', '3'}}, {{'3', '4'}}, {{'3', '5'}}, {{'3', '6'}}, {{'3', '7'}}, {{'3', '8'}}, {{'3', '9'}},
						{{'4', '0'}}, {{'4', '1'}}, {{'4', '2'}}, {{'4', '3'}}, {{'4', '4'}}, {{'4', '5'}}, {{'4', '6'}}, {{'4', '7'}}, {{'4', '8'}}, {{'4', '9'}},
						{{'5', '0'}}, {{'5', '1'}}, {{'5', '2'}}, {{'5', '3'}}, {{'5', '4'}}, {{'5', '5'}}, {{'5', '6'}}, {{'5', '7'}}, {{'5', '8'}}, {{'5', '9'}},
						{{'6', '0'}}, {{'6', '1'}}, {{'6', '2'}}, {{'6', '3'}}, {{'6', '4'}}, {{'6', '5'}}, {{'6', '6'}}, {{'6', '7'}}, {{'6', '8'}}, {{'6', '9'}},
						{{'7', '0'}}, {{'7', '1'}}, {{'7', '2'}}, {{'7', '3'}}, {{'7', '4'}}, {{'7', '5'}}, {{'7', '6'}}, {{'7', '7'}}, {{'7', '8'}}, {{'7', '9'}},
						{{'8', '0'}}, {{'8', '1'}}, {{'8', '2'}}, {{'8', '3'}}, {{'8', '4'}}, {{'8', '5'}}, {{'8', '6'}}, {{'8', '7'}}, {{'8', '8'}}, {{'8', '9'}},
						{{'9', '0'}}, {{'9', '1'}}, {{'9', '2'}}, {{'9', '3'}}, {{'9', '4'}}, {{'9', '5'}}, {{'9', '6'}}, {{'9', '7'}}, {{'9', '8'}}, {{'9', '9'}},
					}
				};

				// special case for "0"
				if (x == 0)
				{
					o->write_character('0');
					return;
				}

				// use a pointer to fill the buffer
				auto buffer_ptr = number_buffer.begin();

				const bool is_negative = std::is_same<NumberType, number_integer_t>::value and not(x >= 0); // see issue #755
				number_unsigned_t abs_value;

				unsigned int n_chars;

				if (is_negative)
				{
					*buffer_ptr = '-';
					abs_value = remove_sign(x);

					// account one more byte for the minus sign
					n_chars = 1 + count_digits(abs_value);
				}
				else
				{
					abs_value = static_cast<number_unsigned_t>(x);
					n_chars = count_digits(abs_value);
				}

				// spare 1 byte for '\0'
				assert(n_chars < number_buffer.size() - 1);

				// jump to the end to generate the string from backward
				// so we later avoid reversing the result
				buffer_ptr += n_chars;

				// Fast int2ascii implementation inspired by "Fastware" talk by Andrei Alexandrescu
				// See: https://www.youtube.com/watch?v=o4-CwDo2zpg
				while (abs_value >= 100)
				{
					const auto digits_index = static_cast<unsigned>((abs_value % 100));
					abs_value /= 100;
					*(--buffer_ptr) = digits_to_99[digits_index][1];
					*(--buffer_ptr) = digits_to_99[digits_index][0];
				}

				if (abs_value >= 10)
				{
					const auto digits_index = static_cast<unsigned>(abs_value);
					*(--buffer_ptr) = digits_to_99[digits_index][1];
					*(--buffer_ptr) = digits_to_99[digits_index][0];
				}
				else
				{
					*(--buffer_ptr) = static_cast<char>('0' + abs_value);
				}

				o->write_characters(number_buffer.data(), n_chars);
			}

			/*!
			@brief dump a floating-point number
			Dump a given floating-point number to output stream @a o. Works internally
			with @a number_buffer.
			@param[in] x  floating-point number to dump
			*/
			void dump_float(number_float_t x)
			{
				// NaN / inf
				if (not std::isfinite(x))
				{
					o->write_characters("null", 4);
					return;
				}

				// If number_float_t is an IEEE-754 single or double precision number,
				// use the Grisu2 algorithm to produce short numbers which are
				// guaranteed to round-trip, using strtof and strtod, resp.
				//
				// NB: The test below works if <long double> == <double>.
				static constexpr bool is_ieee_single_or_double
					= (std::numeric_limits<number_float_t>::is_iec559 and std::numeric_limits<number_float_t>::digits == 24 and std::numeric_limits<number_float_t>::max_exponent == 128) or
					(std::numeric_limits<number_float_t>::is_iec559 and std::numeric_limits<number_float_t>::digits == 53 and std::numeric_limits<number_float_t>::max_exponent == 1024);

				dump_float(x, std::integral_constant<bool, is_ieee_single_or_double>());
			}

			void dump_float(number_float_t x, std::true_type /*is_ieee_single_or_double*/)
			{
				char* begin = number_buffer.data();
				char* end = ::nlohmann::detail::to_chars(begin, begin + number_buffer.size(), x);

				o->write_characters(begin, static_cast<size_t>(end - begin));
			}

			void dump_float(number_float_t x, std::false_type /*is_ieee_single_or_double*/)
			{
				// get number of digits for a float -> text -> float round-trip
				static constexpr auto d = std::numeric_limits<number_float_t>::max_digits10;

				// the actual conversion
				std::ptrdiff_t len = (std::snprintf)(number_buffer.data(), number_buffer.size(), "%.*g", d, x);

				// negative value indicates an error
				assert(len > 0);
				// check if buffer was large enough
				assert(static_cast<std::size_t>(len) < number_buffer.size());

				// erase thousands separator
				if (thousands_sep != '\0')
				{
					const auto end = std::remove(number_buffer.begin(),
						number_buffer.begin() + len, thousands_sep);
					std::fill(end, number_buffer.end(), '\0');
					assert((end - number_buffer.begin()) <= len);
					len = (end - number_buffer.begin());
				}

				// convert decimal point to '.'
				if (decimal_point != '\0' and decimal_point != '.')
				{
					const auto dec_pos = std::find(number_buffer.begin(), number_buffer.end(), decimal_point);
					if (dec_pos != number_buffer.end())
					{
						*dec_pos = '.';
					}
				}

				o->write_characters(number_buffer.data(), static_cast<std::size_t>(len));

				// determine if need to append ".0"
				const bool value_is_int_like =
					std::none_of(number_buffer.begin(), number_buffer.begin() + len + 1,
						[](char c)
						{
							return c == '.' or c == 'e';
						});

				if (value_is_int_like)
				{
					o->write_characters(".0", 2);
				}
			}

			/*!
			@brief check whether a string is UTF-8 encoded
			The function checks each byte of a string whether it is UTF-8 encoded. The
			result of the check is stored in the @a state parameter. The function must
			be called initially with state 0 (accept). State 1 means the string must
			be rejected, because the current byte is not allowed. If the string is
			completely processed, but the state is non-zero, the string ended
			prematurely; that is, the last byte indicated more bytes should have
			followed.
			@param[in,out] state  the state of the decoding
			@param[in,out] codep  codepoint (valid only if resulting state is UTF8_ACCEPT)
			@param[in] byte       next byte to decode
			@return               new state
			@note The function has been edited: a std::array is used.
			@copyright Copyright (c) 2008-2009 Bjoern Hoehrmann <bjoern@hoehrmann.de>
			@sa http://bjoern.hoehrmann.de/utf-8/decoder/dfa/
			*/
			static std::uint8_t decode(std::uint8_t& state, std::uint32_t& codep, const std::uint8_t byte) noexcept
			{
				static const std::array<std::uint8_t, 400> utf8d =
				{
					{
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 00..1F
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 20..3F
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 40..5F
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 60..7F
						1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, // 80..9F
						7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, // A0..BF
						8, 8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // C0..DF
						0xA, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x3, // E0..EF
						0xB, 0x6, 0x6, 0x6, 0x5, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, // F0..FF
						0x0, 0x1, 0x2, 0x3, 0x5, 0x8, 0x7, 0x1, 0x1, 0x1, 0x4, 0x6, 0x1, 0x1, 0x1, 0x1, // s0..s0
						1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, // s1..s2
						1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, // s3..s4
						1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, // s5..s6
						1, 3, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 // s7..s8
					}
				};

				const std::uint8_t type = utf8d[byte];

				codep = (state != UTF8_ACCEPT)
					? (byte & 0x3fu) | (codep << 6u)
					: (0xFFu >> type)& (byte);

				state = utf8d[256u + state * 16u + type];
				return state;
			}

			/*
			 * Overload to make the compiler happy while it is instantiating
			 * dump_integer for number_unsigned_t.
			 * Must never be called.
			 */
			number_unsigned_t remove_sign(number_unsigned_t x)
			{
				assert(false); // LCOV_EXCL_LINE
				return x; // LCOV_EXCL_LINE
			}

			/*
			 * Helper function for dump_integer
			 *
			 * This function takes a negative signed integer and returns its absolute
			 * value as unsigned integer. The plus/minus shuffling is necessary as we can
			 * not directly remove the sign of an arbitrary signed integer as the
			 * absolute values of INT_MIN and INT_MAX are usually not the same. See
			 * #1708 for details.
			 */
			inline number_unsigned_t remove_sign(number_integer_t x) noexcept
			{
				assert(x < 0 and x < (std::numeric_limits<number_integer_t>::max)());
				return static_cast<number_unsigned_t>(-(x + 1)) + 1;
			}

		private:
			/// the output of the serializer
			output_adapter_t<char> o = nullptr;

			/// a (hopefully) large enough character buffer
			std::array<char, 64> number_buffer{ {} };

			/// the locale
			const std::lconv* loc = nullptr;
			/// the locale's thousand separator character
			const char thousands_sep = '\0';
			/// the locale's decimal point character
			const char decimal_point = '\0';

			/// string buffer
			std::array<char, 512> string_buffer{ {} };

			/// the indentation character
			const char indent_char;
			/// the indentation string
			string_t indent_string;

			/// error_handler how to react on decoding errors
			const error_handler_t error_handler;
		};
	}  // namespace detail
}  // namespace nlohmann

// #include <nlohmann/detail/value_t.hpp>

// #include <nlohmann/json_fwd.hpp>


/*!
@brief namespace for Niels Lohmann
@see https://github.com/nlohmann
@since version 1.0.0
*/
namespace nlohmann
{

	/*!
	@brief a class to store JSON values
	@tparam ObjectType type for JSON objects (`std::map` by default; will be used
	in @ref object_t)
	@tparam ArrayType type for JSON arrays (`std::vector` by default; will be used
	in @ref array_t)
	@tparam StringType type for JSON strings and object keys (`std::string` by
	default; will be used in @ref string_t)
	@tparam BooleanType type for JSON booleans (`bool` by default; will be used
	in @ref boolean_t)
	@tparam NumberIntegerType type for JSON integer numbers (`int64_t` by
	default; will be used in @ref number_integer_t)
	@tparam NumberUnsignedType type for JSON unsigned integer numbers (@c
	`uint64_t` by default; will be used in @ref number_unsigned_t)
	@tparam NumberFloatType type for JSON floating-point numbers (`double` by
	default; will be used in @ref number_float_t)
	@tparam AllocatorType type of the allocator to use (`std::allocator` by
	default)
	@tparam JSONSerializer the serializer to resolve internal calls to `to_json()`
	and `from_json()` (@ref adl_serializer by default)
	@requirement The class satisfies the following concept requirements:
	- Basic
	 - [DefaultConstructible](https://en.cppreference.com/w/cpp/named_req/DefaultConstructible):
	   JSON values can be default constructed. The result will be a JSON null
	   value.
	 - [MoveConstructible](https://en.cppreference.com/w/cpp/named_req/MoveConstructible):
	   A JSON value can be constructed from an rvalue argument.
	 - [CopyConstructible](https://en.cppreference.com/w/cpp/named_req/CopyConstructible):
	   A JSON value can be copy-constructed from an lvalue expression.
	 - [MoveAssignable](https://en.cppreference.com/w/cpp/named_req/MoveAssignable):
	   A JSON value van be assigned from an rvalue argument.
	 - [CopyAssignable](https://en.cppreference.com/w/cpp/named_req/CopyAssignable):
	   A JSON value can be copy-assigned from an lvalue expression.
	 - [Destructible](https://en.cppreference.com/w/cpp/named_req/Destructible):
	   JSON values can be destructed.
	- Layout
	 - [StandardLayoutType](https://en.cppreference.com/w/cpp/named_req/StandardLayoutType):
	   JSON values have
	   [standard layout](https://en.cppreference.com/w/cpp/language/data_members#Standard_layout):
	   All non-static data members are private and standard layout types, the
	   class has no virtual functions or (virtual) base classes.
	- Library-wide
	 - [EqualityComparable](https://en.cppreference.com/w/cpp/named_req/EqualityComparable):
	   JSON values can be compared with `==`, see @ref
	   operator==(const_reference,const_reference).
	 - [LessThanComparable](https://en.cppreference.com/w/cpp/named_req/LessThanComparable):
	   JSON values can be compared with `<`, see @ref
	   operator<(const_reference,const_reference).
	 - [Swappable](https://en.cppreference.com/w/cpp/named_req/Swappable):
	   Any JSON lvalue or rvalue of can be swapped with any lvalue or rvalue of
	   other compatible types, using unqualified function call @ref swap().
	 - [NullablePointer](https://en.cppreference.com/w/cpp/named_req/NullablePointer):
	   JSON values can be compared against `std::nullptr_t` objects which are used
	   to model the `null` value.
	- Container
	 - [Container](https://en.cppreference.com/w/cpp/named_req/Container):
	   JSON values can be used like STL containers and provide iterator access.
	 - [ReversibleContainer](https://en.cppreference.com/w/cpp/named_req/ReversibleContainer);
	   JSON values can be used like STL containers and provide reverse iterator
	   access.
	@invariant The member variables @a m_value and @a m_type have the following
	relationship:
	- If `m_type == value_t::object`, then `m_value.object != nullptr`.
	- If `m_type == value_t::array`, then `m_value.array != nullptr`.
	- If `m_type == value_t::string`, then `m_value.string != nullptr`.
	The invariants are checked by member function assert_invariant().
	@internal
	@note ObjectType trick from http://stackoverflow.com/a/9860911
	@endinternal
	@see [RFC 7159: The JavaScript Object Notation (JSON) Data Interchange
	Format](http://rfc7159.net/rfc7159)
	@since version 1.0.0
	@nosubgrouping
	*/
	NLOHMANN_BASIC_JSON_TPL_DECLARATION
		class basic_json
	{
	private:
		template<detail::value_t> friend struct detail::external_constructor;
		friend ::nlohmann::json_pointer<basic_json>;
		friend ::nlohmann::detail::parser<basic_json>;
		friend ::nlohmann::detail::serializer<basic_json>;
		template<typename BasicJsonType>
		friend class ::nlohmann::detail::iter_impl;
		template<typename BasicJsonType, typename CharType>
		friend class ::nlohmann::detail::binary_writer;
		template<typename BasicJsonType, typename SAX>
		friend class ::nlohmann::detail::binary_reader;
		template<typename BasicJsonType>
		friend class ::nlohmann::detail::json_sax_dom_parser;
		template<typename BasicJsonType>
		friend class ::nlohmann::detail::json_sax_dom_callback_parser;

		/// workaround type for MSVC
		using basic_json_t = NLOHMANN_BASIC_JSON_TPL;

		// convenience aliases for types residing in namespace detail;
		using lexer = ::nlohmann::detail::lexer<basic_json>;
		using parser = ::nlohmann::detail::parser<basic_json>;

		using primitive_iterator_t = ::nlohmann::detail::primitive_iterator_t;
		template<typename BasicJsonType>
		using internal_iterator = ::nlohmann::detail::internal_iterator<BasicJsonType>;
		template<typename BasicJsonType>
		using iter_impl = ::nlohmann::detail::iter_impl<BasicJsonType>;
		template<typename Iterator>
		using iteration_proxy = ::nlohmann::detail::iteration_proxy<Iterator>;
		template<typename Base> using json_reverse_iterator = ::nlohmann::detail::json_reverse_iterator<Base>;

		template<typename CharType>