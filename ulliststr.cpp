#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

void ULListStr::push_back(const std::string& val)
{
  if(tail_ == NULL || tail_->last == 10 || tail_->last == 0)
  {
    Item *temp = new Item;
    temp->val[0] = val;
    temp->first = 0;
    temp->last = 1;
    temp->next = nullptr;
    if(tail_ != nullptr)
    {
      temp->prev = tail_;
      tail_->next = temp;
    }

    tail_ = temp;

    if(head_ == nullptr)
    {
      head_ = tail_;
    }
  }
  else
  {
    if(tail_ != nullptr)
    {
      tail_->val[tail_->last] = val;
      tail_->last = tail_->last + 1;
      tail_->next = nullptr;
    }
    else
    {
      return;
    }
  }
  size_++;
}

void ULListStr::pop_back()
{
  if(!empty())
  {
    if(tail_->last != 0)
    {
      //tail_->val[tail_->last-1] = "";
      tail_->last = tail_->last-1;
    }
    if(tail_->last - tail_->first == 0)
    {   
      Item* temp = tail_;
      if(tail_->prev != nullptr)
      {
        tail_ = tail_->prev;
        tail_->next = nullptr;
      }
      else
      {
        tail_ = nullptr;
        head_ = nullptr;
      }
      delete temp;
    }
    else if(tail_ != nullptr)
    {
      tail_->next = nullptr; 
    }
    else
    {
      head_ = nullptr;
    }
    size_--;
  }
}

void ULListStr::push_front(const std::string& val)
{
  if(head_ == NULL || head_->first == 0)
  {
    Item *temp = new Item;
    temp->val[9] = val;
    temp->first = 9;
    temp->last = 10;
    temp->next = head_;
    temp->prev = nullptr;
    if(head_ != nullptr)
    {
      head_->prev = temp;
    }
    head_ = temp;
  }
  else
  {
    if(head_ != nullptr)
    {
      head_->first = head_->first - 1;
      head_->val[head_->first] = val;
      head_->prev = nullptr;
    }   
  }
  if(tail_ == nullptr)
  {
    tail_ = head_;
  }
  size_++; //might need to increment number of elements within the array within the node
}

void ULListStr::pop_front()
{
  if(!empty())
  {
    if(head_->last != 0)
    {
      //head_->val[head_->first] = ""; 
      head_->first++;
    }
    if(head_->last - head_->first == 0)
    {   
      Item* temp = head_;
      //temp = head_;
      if(head_->next != nullptr)
      {
        head_ = head_->next;
        head_->prev = nullptr;
      }
      else
      {
        head_ = nullptr;
        tail_ = nullptr;
      }
      delete temp;
    }
    else if(head_ != nullptr)
    {
      head_->prev = nullptr; 
    }
    else
    {
      tail_ = nullptr;
    }
    size_ = size_ - 1;
  }
}

std::string const & ULListStr::back() const
{
  static const std::string myString = "";
  if(tail_ == NULL)
  {
    return myString;
  }
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const
{
  static const std::string myString = "";
  if(head_ == NULL)
  {
    return myString;
  }
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if(loc >= size_ || loc < 0)
  {
    return nullptr; //this has issues don't know how to fix
  }
  Item* temp;
  if(head_->first == head_->last)
  {
    return NULL;
  }
  else
  {
    temp = head_;
  }
  int count = temp->first;
  for(size_t i = 0; i < size_; i++)
  {
    if(count < temp->last)
    {
      if(i == loc)
      {
        return &(temp->val[count]);
      }
      count++;
    }
    else
    {
      temp = temp->next;
      count = temp->first;

      if(i == loc)
      {
        return &(temp->val[count]);
      }
      count++;
    }
  }


  //return NULL;
}
