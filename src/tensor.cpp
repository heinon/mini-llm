#include "tensor.hpp"
#include <iostream>

Tensor::Tensor(std::vector<int> shape) : shape_(std::move(shape)), strides_(computeStrides(shape_))
{
    auto total = numel();
    data_.resize(total);
}

std::vector<int> Tensor::computeStrides(std::vector<int>& shape)
{
    std::vector<int> strides(shape.size());
    int stride = 1;
    for (int i = shape.size() - 1; i >= 0; i--)
    {
        strides[i] = stride;
        stride = stride * shape[i];
    }

    return strides;
}

float Tensor::get(std::vector<int>& index) const
{
    int offset = 0;
    for (int i = 0; i < index.size(); i++)
    {
        offset = offset + (index[i] * strides_[i]);
    }

    return data_[offset];
}

void Tensor::fill(std::vector<float> data)
{
    data_ = std::move(data);
}

void Tensor::print() const
{
    std::cout << numel() << std::endl;
}

int Tensor::numel() const
{
    int total = 1;
    for (int dim : shape_)
    {
        total = total * dim;
    }
    
    return total;
}