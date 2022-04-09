#include "vector.h"

#include <cstdio>
#include <cstdlib>
#include <memory>
template <typename T>
Vector<T>::Vector() {
  this->elements = static_cast<T*>(malloc(sizeof(T)));
  this->count = 0;
}

template <typename T>
Vector<T>::~Vector() {
  free(this->elements);
}
template <typename T>
void Vector<T>::push(T element) {
  this->count++;
  this->elements =
      static_cast<T>(realloc(this->elements, this->count * sizeof(T)));
  this->elements[this->count - 1] = element;
}

template <typename T>
void Vector<T>::pop(T element) {
  this->count--;
  this->elements =
      static_cast<T>(realloc(this->elements, this->count * sizeof(T)));
}

template <typename T>
void Vector<T>::remove(T index) {
  for (int i = index; i < count; i++) this->elements[i] = this->elements[i + 1];
  this->count--;
  this->elements =
      static_cast<T>(realloc(this->elements, this->count * sizeof(T)));
}

template <typename T>
void Vector<T>::insert(T index, T element) {
  count++;
  this->elements =
      static_cast<T>(realloc(this->elements, this->count * sizeof(T)));
  for (int i = count; i > index; i--) {
    this->elements[i] = this->elements[i - 1];
  }
  this->elements[index] = element;
}

template <typename T>
const T& Vector<T>::get(int index) {
  return this->elements[index];
}

template <typename T>
void Vector<T>::set(int index, T element) {
  if (index >= this->count || index < 0) {
    return;
  }

  this->elements[index] = element;
}

template <typename T>
int Vector<T>::countV() {
  return this->count;
}

template <typename T>
void Vector<T>::sort() {
  for (int i = 0; i < this->element_count - 1; i++) {
    for (int j = i; j < this->element_count; j++) {
      if (cmp(this->elements[i], this->elements[j])) {
        swap(this->elements[i], this->elements[j]);
      }
    }
  }
}