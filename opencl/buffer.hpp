// Copyright (c)    2013 Martin Stumpf
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once
#ifndef HPX_OPENCL_BUFFER_HPP__
#define HPX_OPENCL_BUFFER_HPP__


#include <hpx/include/components.hpp>
#include <hpx/lcos/future.hpp>

#include "server/buffer.hpp"
#include "event.hpp"

#include <vector>

namespace hpx {
namespace opencl { 


    class buffer
      : public hpx::components::client_base<
          buffer, hpx::components::stub_base<server::buffer>
        >
    {
    
        typedef hpx::components::client_base<
            buffer, hpx::components::stub_base<server::buffer>
            > base_type;

        public:
            // Empty constructor, necessary for hpx purposes
            buffer(){}

            // Constructor
            buffer(hpx::future<hpx::naming::id_type> const& gid)
              : base_type(gid)
            {}
            
            /////////////////////////////////////////////////
            /// Exposed Component functionality
            /// 
            
            // Get buffer size
            hpx::lcos::future<size_t>
            size() const;

            // Read Buffer
            hpx::lcos::future<hpx::opencl::event>
            enqueue_read(size_t offset, size_t size) const;
            
            hpx::lcos::future<hpx::opencl::event>
            enqueue_read(size_t offset, size_t size,
                                       hpx::opencl::event event) const;

            hpx::lcos::future<hpx::opencl::event>
            enqueue_read(size_t offset, size_t size,
                                  std::vector<hpx::opencl::event> events) const;

            // Write Buffer
            hpx::lcos::future<hpx::opencl::event>
            enqueue_write(size_t offset, size_t size, const void* data) const;
            
            hpx::lcos::future<hpx::opencl::event>
            enqueue_write(size_t offset, size_t size, const void* data,
                                       hpx::opencl::event event) const;
            
            hpx::lcos::future<hpx::opencl::event>
            enqueue_write(size_t offset, size_t size, const void* data,
                                  std::vector<hpx::opencl::event> events) const;

            // Fill Buffer
            hpx::lcos::future<hpx::opencl::event>
            enqueue_fill(const void* pattern, size_t pattern_size,
                                       size_t offset, size_t size) const;
            
            hpx::lcos::future<hpx::opencl::event>
            enqueue_fill(const void* pattern, size_t pattern_size,
                                       size_t offset, size_t size,
                                       hpx::opencl::event event) const;
            
            hpx::lcos::future<hpx::opencl::event>
            enqueue_fill(const void* pattern, size_t pattern_size,
                                  size_t offset, size_t size,
                                  std::vector<hpx::opencl::event> events) const;
            
            // Copy Buffer
            hpx::lcos::future<hpx::opencl::event>
            enqueue_copy(buffer src, size_t src_offset, size_t dst_offset,
                                 size_t size) const;

            hpx::lcos::future<hpx::opencl::event>
            enqueue_copy(buffer src, size_t src_offset, size_t dst_offset,
                                 size_t size,
                                 hpx::opencl::event event) const;

            hpx::lcos::future<hpx::opencl::event>
            enqueue_copy(buffer src, size_t src_offset, size_t dst_offset,
                                 size_t size,
                                 std::vector<hpx::opencl::event> events) const;


            /* TODO
             * clEnqueueReadBufferRect
             * clEnqueueWriteBufferRect
             * clEnqueueCopyBuffer
             * clEnqueueCopyBufferRect
             */

    };

}}



#endif// HPX_OPENCL_BUFFER_HPP__