#pragma once

namespace parser
{

	/// @brief expression(): try to generate an expression subtree
	/// from the tokenized source
	void expression();

	/// @brief term(): try to generate a term subtree from the tokenized source
	void term();

} // namespace parser
