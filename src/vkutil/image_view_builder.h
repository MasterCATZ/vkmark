/*
 * Copyright © 2017 Collabora Ltd.
 *
 * This file is part of vkmark.
 *
 * vkmark is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * vkmark is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with vkmark. If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors:
 *   Alexandros Frantzis <alexandros.frantzis@collabora.com>
 */

#pragma once

#include <vulkan/vulkan.hpp>

#include "managed_resource.h"

class VulkanState;

namespace vkutil
{

class ImageViewBuilder
{
public:
    ImageViewBuilder(VulkanState& vulkan);

    ImageViewBuilder& set_image(vk::Image image);
    ImageViewBuilder& set_format(vk::Format format);
    ImageViewBuilder& set_aspect_mask(vk::ImageAspectFlags mask);

    ManagedResource<vk::ImageView> build();

private:
    VulkanState& vulkan;
    vk::Image image;
    vk::Format format;
    vk::ImageAspectFlags aspect_mask;
};

}
