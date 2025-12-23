#ifndef LIMITED_VECTOR_HPP
#define LIMITED_VECTOR_HPP

#include <vector>
#include <stdexcept>

/**
 * @brief A vector-like container that maintains a maximum size.
 *        Automatically removes the oldest elements when the size exceeds the limit.
 *
 * @tparam T The type of elements stored in the container.
 */
template <typename T> class LimitedVector {
  public:
    /**
     * @brief Constructor to initialize the vector with a maximum size.
     *
     * @param max_size The maximum number of elements the vector can hold.
     */
    explicit LimitedVector(size_t max_size) : max_size_(max_size) {}

    /**
     * @brief Adds an element to the vector. If the vector exceeds the maximum size,
     *        the oldest element is removed.
     *
     * @param value The element to be added.
     */
    void push_back(const T &value) {
        if (data_.size() >= max_size_) {
            data_.erase(data_.begin());
        }
        data_.push_back(value);
    }

    /**
     * @brief Access an element by index.
     *
     * @param index The index of the element to access.
     * @return The element at the specified index.
     */
    T &operator[](size_t index) { return data_[index]; }

    /**
     * @brief Access an element by index (const version).
     *
     * @param index The index of the element to access.
     * @return The element at the specified index.
     */
    const T &operator[](size_t index) const { return data_[index]; }

    /**
     * @brief Gets the first element in the vector.
     *
     * @return A reference to the first element.
     */
    T &front() {
        if (empty())
            throw std::out_of_range("Attempted to access front of empty vector.");
        return data_.front();
    }

    /**
     * @brief Gets the first element in the vector (const version).
     *
     * @return A const reference to the first element.
     */
    const T &front() const {
        if (empty())
            throw std::out_of_range("Attempted to access front of empty vector.");
        return data_.front();
    }

    /**
     * @brief Gets the last element in the vector.
     *
     * @return A reference to the last element.
     */
    T &back() {
        if (empty())
            throw std::out_of_range("Attempted to access back of empty vector.");
        return data_.back();
    }

    /**
     * @brief Gets the last element in the vector (const version).
     *
     * @return A const reference to the last element.
     */
    const T &back() const {
        if (empty())
            throw std::out_of_range("Attempted to access back of empty vector.");
        return data_.back();
    }

    /**
     * @brief Gets the current size of the vector.
     *
     * @return The number of elements in the vector.
     */
    size_t size() const { return data_.size(); }

    /**
     * @brief Checks if the vector is empty.
     *
     * @return True if the vector is empty, false otherwise.
     */
    bool empty() const { return data_.empty(); }

    /**
     * @brief Clears all elements in the vector.
     */
    void clear() { data_.clear(); }

    /**
     * @brief Erases the element at the given position.
     *
     * @param pos Iterator pointing to the element to erase.
     * @return Iterator pointing to the element following the erased one.
     */
    typename std::vector<T>::iterator erase(typename std::vector<T>::iterator pos) { return data_.erase(pos); }

    /**
     * @brief Returns an iterator to the beginning of the vector.
     *
     * @return Iterator pointing to the first element.
     */
    typename std::vector<T>::iterator begin() { return data_.begin(); }

    /**
     * @brief Returns a const iterator to the beginning of the vector.
     *
     * @return Const iterator pointing to the first element.
     */
    typename std::vector<T>::const_iterator begin() const { return data_.begin(); }

    /**
     * @brief Returns an iterator to the end of the vector.
     *
     * @return Iterator pointing to the position after the last element.
     */
    typename std::vector<T>::iterator end() { return data_.end(); }

    /**
     * @brief Returns a const iterator to the end of the vector.
     *
     * @return Const iterator pointing to the position after the last element.
     */
    typename std::vector<T>::const_iterator end() const { return data_.end(); }

  private:
    size_t max_size_;     ///< The maximum number of elements the vector can hold.
    std::vector<T> data_; ///< The underlying storage for the vector elements.
};

#endif // LIMITED_VECTOR_HPP
