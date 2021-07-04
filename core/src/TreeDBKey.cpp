/*
    Copyright (c) 2018-2019 Xavier Leclercq

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

#include "TreeDBKey.h"

namespace DiplodocusDB
{

TreeDBKey::TreeDBKey(const char* key)
    : m_value(key)
{
}

TreeDBKey::TreeDBKey(const std::string& key)
    : m_value(key)
{
}

TreeDBKey::~TreeDBKey()
{
}

const std::string& TreeDBKey::value() const
{
    return m_value;
}

bool TreeDBKey::isRoot() const
{
    return (m_value == "/");
}

bool TreeDBKey::isNull() const
{
    return (m_value == "");
}

TreeDBKey TreeDBKey::parentKey() const
{
    TreeDBKey result("");
    size_t pos = m_value.rfind('/');
    if ((pos == 0) && (m_value.size() > 1))
    {
        result = TreeDBKey("/");
    }
    else if (pos != std::string::npos)
    {
        result = TreeDBKey(m_value.substr(0, pos));
    }
    return result;
}

std::string TreeDBKey::base() const
{
    std::string result;
    size_t pos = m_value.rfind('/');
    if (pos != std::string::npos)
    {
        result = m_value.substr(pos + 1);
    }
    else
    {
        result = m_value;
    }
    return result;
}

bool TreeDBKey::operator ==(const TreeDBKey& other) const
{
    return (m_value == other.m_value);
}

bool TreeDBKey::operator !=(const TreeDBKey& other) const
{
    return (m_value != other.m_value);
}

bool TreeDBKey::operator <(const TreeDBKey& other) const
{
    return (m_value < other.m_value);
}

bool TreeDBKey::operator >(const TreeDBKey& other) const
{
    return (m_value > other.m_value);
}

}
