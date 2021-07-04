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

#include "TreeDBNode.h"
#include "TreeDBNodeImpl.h"

namespace DiplodocusDB
{

TreeDBNode::TreeDBNode(std::shared_ptr<TreeDBNodeImpl> impl)
    : m_impl(impl)
{
}

TreeDBNode::operator bool() const
{
    return static_cast<bool>(m_impl);
}

bool TreeDBNode::operator !() const
{
    return !m_impl;
}

bool TreeDBNode::operator ==(const TreeDBNode& other) const
{
    return (m_impl == other.m_impl);
}

bool TreeDBNode::operator !=(const TreeDBNode& other) const
{
    return (m_impl != other.m_impl);
}

const std::string& TreeDBNode::name() const
{
    return m_impl->name();
}

bool TreeDBNode::isRoot() const
{
    return m_impl->isRoot();
}

std::shared_ptr<TreeDBNodeImpl>& TreeDBNode::impl()
{
    return m_impl;
}

}
