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

#include <stdbool.h>
#include <stdint.h>

#include "platform.h"

#if defined(USE_RADAR)

#include "build/debug.h"

#include "common/utils.h"

#include "sensors/radar.h"

msp_radar_pos_message_t radar_peers[RADAR_MAX_POIS];
uint32_t radar_timestamps[RADAR_MAX_POIS];

void radarProcess(timeUs_t currentTimeUs)
{
    UNUSED(currentTimeUs);
}

void radarInit(void)
{
}

/*msp_radar_pos_message_t* radarGetPeerHandle(uint8_t index)
{
    return &radar_peers[index];
}*/

bool radarGetPeerHealthy(uint8_t index)
{
    return millis() - radar_timestamps[index] < RADAR_PEER_TIMEOUT_MS;
}

uint8_t radarGetNextHealthyPeer(uint8_t currentId)
{
    for (uint8_t i = 1; i < RADAR_MAX_POIS; i++) {
        uint8_t next_peer = (currentId + i) % RADAR_MAX_POIS;
        if (radarGetPeerHealthy(next_peer)) {
            return next_peer;
        }
    }
    return currentId;
}

#endif
