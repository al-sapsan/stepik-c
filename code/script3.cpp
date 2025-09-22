/************************************************************************
 * 1. General Information (filename, purpose, platform, version, date)
 * @file script3.cpp
 * @brief RandomPassword class implementation (embedded-style, no I/O, no main)
 * @version 1.0 (Generic Embedded C++)
 * @date 2025-09-22
 *
 * @warning Uses rand(); seed externally with srand() before generating
 * @note Fixed-size internal buffers, no dynamic containers
 *************************************************************************/

//==============================================================================
// 2. Libraries used (grouped by purpose)
//==============================================================================
/* *** Core *** */
#include "emb_style_cpp.h"

/* *** C stdlib *** */
#include <cstdlib>

/* *** C++ stdlib (task API) *** */
#include <string>

//==============================================================================
// 3. Data types
//==============================================================================
/* *** Typedefs ***
 * Types are provided by emb_style_cpp.h: i16_t, u16_t, ch_t, etc.
 */

//==============================================================================
// 4. Constants
//==============================================================================
/* *** Constants *** */
constexpr u16_t MAX_CHARSET_SIZE = 128U;

//==============================================================================
// 5. Function Prototypes (Doxygen)
//==============================================================================
/* Not applicable: class is defined below with inline methods */

//==============================================================================
// 6. Main function
//==============================================================================
/* Not applicable per task: no main() and no I/O */

//==============================================================================
// 7. Function implementations
//==============================================================================
/*** RandomPassword class ***/
/**
 * @brief Random password generator (embedded-style, no I/O, no main)
 */
class RandomPassword
{
public:
	//============================================================================
	// Public API
	//============================================================================
	/**
	 * @brief Construct a new RandomPassword object
	 * @param psw_chars Allowed characters (std::string as per task)
	 * @param min_length Minimal password length (inclusive)
	 * @param max_length Maximal password length (inclusive)
	 */
	RandomPassword(const std::string &psw_chars, int min_length, int max_length)
	{
		if (min_length < 0) { min_length = 0; }
		if (max_length < 0) { max_length = 0; }
		if (min_length > max_length) { int t = min_length; min_length = max_length; max_length = t; }
		m_min_len_i16 = static_cast<i16_t>(min_length);
		m_max_len_i16 = static_cast<i16_t>(max_length);

		i16_t copy_len = static_cast<i16_t>(psw_chars.size());
		if (copy_len > static_cast<i16_t>(MAX_CHARSET_SIZE)) { copy_len = static_cast<i16_t>(MAX_CHARSET_SIZE); }
		for (i16_t i = 0; i < copy_len; ++i)
		{
			m_charset_buf[i] = psw_chars[static_cast<size_t>(i)];
		}
		m_charset_len_i16 = copy_len;

		if (m_charset_len_i16 == 0)
		{
			m_charset_buf[0] = 'a';
			m_charset_len_i16 = 1;
		}
		if (m_min_len_i16 <= 0 && m_max_len_i16 <= 0)
		{
			m_min_len_i16 = 1;
			m_max_len_i16 = 1;
		}
	}

	/**
	 * @brief Generate a random password
	 * @return std::string password
	 */
	std::string operator()() const
	{
		i16_t range = static_cast<i16_t>(m_max_len_i16 - m_min_len_i16 + 1);
		i16_t psw_len = static_cast<i16_t>(m_min_len_i16 + (range > 0 ? (std::rand() % range) : 0));
		std::string psw;
		psw.reserve(static_cast<size_t>(psw_len));
		for (i16_t i = 0; i < psw_len; ++i)
		{
			i16_t idx = static_cast<i16_t>(std::rand() % m_charset_len_i16);
			psw.push_back(m_charset_buf[static_cast<size_t>(idx)]);
		}
		return psw;
	}

private:
	//============================================================================
	// Private data
	//============================================================================
	ch_t m_charset_buf[MAX_CHARSET_SIZE] = {0};
	i16_t m_charset_len_i16 = 0;
	i16_t m_min_len_i16 = 1;
	i16_t m_max_len_i16 = 1;
};
