#ifndef LIMITED_VECTOR_TPP
#define LIMITED_VECTOR_TPP

#include "limited_vector.hpp"

template <typename T> LimitedVector<T>::LimitedVector(size_t max_size) : max_size_(max_size) {}

template <typename T> void LimitedVector<T>::push_back(const T &value) {
    if (data_.size() >= max_size_) {
        data_.erase(data_.begin());
    }
    data_.push_back(value);
}

template <typename T> T &LimitedVector<T>::operator[](size_t index) { return data_[index]; }

template <typename T> const T &LimitedVector<T>::operator[](size_t index) const { return data_[index]; }

template <typename T> T &LimitedVector<T>::front() {
    if (empty()) {
        throw std::out_of_range("Attempted to access the front of an empty vector.");
    }
    return data_.front();
}

template <typename T> const T &LimitedVector<T>::front() const {
    if (empty()) {
        throw std::out_of_range("Attempted to access the front of an empty vector.");
    }
    return data_.front();
}

template <typename T> T &LimitedVector<T>::back() {
    if (empty()) {
        throw std::out_of_range("Attempted to access the back of an empty vector.");
    }
    return data_.back();
}

template <typename T> const T &LimitedVector<T>::back() const {
    if (empty()) {
        throw std::out_of_range("Attempted to access the back of an empty vector.");
    }
    return data_.back();
}

template <typename T> size_t LimitedVector<T>::size() const { return data_.size(); }

template <typename T> bool LimitedVector<T>::empty() const { return data_.empty(); }

template <typename T> void LimitedVector<T>::clear() { data_.clear(); }

template <typename T> typename std::vector<T>::iterator LimitedVector<T>::begin() { return data_.begin(); }

template <typename T> typename std::vector<T>::const_iterator LimitedVector<T>::begin() const { return data_.begin(); }

template <typename T> typename std::vector<T>::iterator LimitedVector<T>::end() { return data_.end(); }

template <typename T> typename std::vector<T>::const_iterator LimitedVector<T>::end() const { return data_.end(); }

#endif // LIMITED_VECTOR_TPP
