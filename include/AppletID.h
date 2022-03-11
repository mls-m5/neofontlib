/** @file       AppletID.h
 *  @brief      Applet ID Number Definitions.
 *  @copyright  (c) 2006 Alquanto. All Rights Reserved.
 */

#pragma once

#include <cstdint>

// Smallest permitted unregistered ID.
constexpr uint16_t kAppletID_UserMin(0x7170);
// Larges permitted unregistered ID.
constexpr uint16_t kAppletID_UserMax(0x717f);

// Smallest permitted Flickr group ID.
constexpr uint16_t kAppletID_GroupMin(0x7100);
// Largest permitted Flickr group ID.
constexpr uint16_t kAppletID_GroupMax(0x717f);

// Smallest AS/RL ID.
constexpr uint16_t kAppletID_ASMin(0xa000);
// Largest AS/RL ID.
constexpr uint16_t kAppletID_ASMax(0xafff);
