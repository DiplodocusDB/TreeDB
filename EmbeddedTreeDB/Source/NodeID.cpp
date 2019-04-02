/*
    Copyright (c) 2019 Xavier Leclercq

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

#include "NodeID.h"
#include "Utilities.h"

namespace DiplodocusDB
{

NodeID::NodeID()
    : m_value(0)
{
}

NodeID::NodeID(size_t value)
    : m_value(value)
{
}

bool NodeID::operator ==(const NodeID& other) const
{
    return (m_value == other.m_value);
}

bool NodeID::operator !=(const NodeID& other) const
{
    return (m_value != other.m_value);
}

void NodeID::read(PageRepositoryReader& reader, Ishiko::Error& error)
{
    // TODO: this needs to decode LEB128
    uint8_t id;
    reader.read((char*)&id, 1, error);
    if (!error)
    {
        m_value = id;
    }
}

void NodeID::write(PageRepositoryWriter& writer, Ishiko::Error& error) const
{
    char buffer[20];
    size_t n = Utilities::encodeLEB128(m_value, buffer);
    writer.write(buffer, n, error);
}

}