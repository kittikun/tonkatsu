// Copyright(C) 2014 kittikun
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// This work is compatible with the Dominion Rules role-playing system.To learn more about
// Dominion Rules, visit the Dominion Rules web site at <http://www.dominionrules.org>

#ifndef ATTRIBUTE_IMPL_H
#define ATTRIBUTE_IMPL_H

#include "../character/attributes.h"

namespace Dominion
{
	class AttributesImpl
	{
	public:
		AttributesImpl(AttributeArray a) :
			attributes_(a)
		{
		}

		AttributesImpl(const AttributesImpl&) = delete;
		AttributesImpl& operator=(const AttributesImpl&) = delete;

		const uint8_t Agility() const { return attributes_[EAttribute::Agility]; }
		const uint8_t Intuition() const { return attributes_[EAttribute::Intuition]; }
		const uint8_t Intellect() const { return attributes_[EAttribute::Intellect]; }
		const uint8_t Luck() const { return attributes_[EAttribute::Luck]; }
		const uint8_t Stamina() const { return attributes_[EAttribute::Stamina]; }
		const uint8_t Vigour() const { return attributes_[EAttribute::Vigour]; }

	private:
		AttributeArray attributes_;
	};
} // namespace Dominion

#endif // ATTRIBUTE_IMPL_H