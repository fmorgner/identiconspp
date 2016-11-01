#ifndef FMO_IDENTICONSPP_BYTE_ITERATOR_H
#define FMO_IDENTICONSPP_BYTE_ITERATOR_H

#include <cstdint>
#include <iterator>
#include <string>

struct byte_iterator : std::iterator<std::input_iterator_tag, std::uint8_t>
  {
  using __super = std::iterator<std::input_iterator_tag, std::uint8_t>;
  using __super::pointer;
  using __super::reference;
  using __super::iterator_category;
  using __super::value_type;
  using __super::difference_type;

  byte_iterator() = default;

  byte_iterator(std::string const & str) :
    m_str{str.size() % 2 ? throw std::invalid_argument{"supplied string has uneven length."} : str.c_str()},
    m_end{m_str + str.size()} { }

  byte_iterator & operator++()
    {
    if((m_str += 2) >= m_end)
      {
      m_str = nullptr;
      }

    return *this;
    }

  byte_iterator operator++(int)
    {
    auto old = *this;
    ++(*this);
    return old;
    }

  reference operator*() const
    {
    auto byte = std::string{m_str, m_str + 2};
    return m_val = std::stoul(byte, nullptr, 16);
    }

  bool operator==(byte_iterator const & other) const
    {
    return m_str == other.m_str;
    }

  bool operator!=(byte_iterator const & other) const
    {
    return !(*this == other);
    }

  value_type const * operator->()
    {
    return reinterpret_cast<std::uint8_t const *>(m_str);
    }

  private:
    char const * m_str;
    char const * const m_end{};
    value_type mutable m_val{};
  };

#endif
