/*
 * This file is part of Cleanflight and Betaflight.
 *
 * Cleanflight and Betaflight are free software. You can redistribute
 * this software and/or modify this software under the terms of the
 * GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Cleanflight and Betaflight are distributed in the hope that they
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "drivers/time.h"

#define RADAR_MAX_POIS 6
#define RADAR_PEER_TIMEOUT_MS 3000

typedef struct msp_radar_pos_message_t {
    uint8_t radar_no;
    uint8_t state;
    int32_t lat;
    int32_t lon;
    int32_t alt;
    uint16_t heading;
    uint16_t speed;
    uint8_t lq;
} msp_radar_pos_message_t;

void radarInit(void);
void radarProcess(timeUs_t currentTimeUs);
//msp_radar_pos_message_t* radarGetPeerHandle(uint8_t index);
uint8_t radarGetNextHealthyPeer(uint8_t currentId);

extern msp_radar_pos_message_t radar_peers[RADAR_MAX_POIS];
extern uint32_t radar_timestamps[RADAR_MAX_POIS];
