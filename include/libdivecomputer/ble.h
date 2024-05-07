/*
 * libdivecomputer
 *
 * Copyright (C) 2019 Jef Driesen
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301 USA
 */

#ifndef DC_BLE_H
#define DC_BLE_H

#include "ioctl.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * Get the remote device name.
 */
#define DC_IOCTL_BLE_GET_NAME   DC_IOCTL_IOR('b', 0, DC_IOCTL_SIZE_VARIABLE)

/**
 * Get the bluetooth authentication PIN code.
 *
 * The data format is a NULL terminated string.
 */
#define DC_IOCTL_BLE_GET_PINCODE   DC_IOCTL_IOR('b', 1, DC_IOCTL_SIZE_VARIABLE)

/**
 * Get/set the bluetooth authentication access code.
 *
 * The data format is a variable sized byte array.
 */
#define DC_IOCTL_BLE_GET_ACCESSCODE   DC_IOCTL_IOR('b', 2, DC_IOCTL_SIZE_VARIABLE)
#define DC_IOCTL_BLE_SET_ACCESSCODE   DC_IOCTL_IOW('b', 2, DC_IOCTL_SIZE_VARIABLE)

/**
 * Perform a BLE characteristic read/write operation.
 *
 * The UUID of the characteristic must be specified as a #dc_ble_uuid_t
 * data structure. If the operation requires additional data as in- or
 * output, the buffer must be located immediately after the
 * #dc_ble_uuid_t data structure. The size of the ioctl request is the
 * total size, including the size of the #dc_ble_uuid_t structure.
 */
#define DC_IOCTL_BLE_CHARACTERISTIC_READ  DC_IOCTL_IOR('b', 3, DC_IOCTL_SIZE_VARIABLE)
#define DC_IOCTL_BLE_CHARACTERISTIC_WRITE DC_IOCTL_IOW('b', 3, DC_IOCTL_SIZE_VARIABLE)

/**
 * Bluetooth UUID (128 bits).
 */
typedef unsigned char dc_ble_uuid_t[16];

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* DC_BLE_H */
