/** @file       NeoCharacter.h
 *  @brief      Neo font character object header file.
 *  @copyright  (c) 2006 Alquanto. All Rights Reserved.
 */
#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

/** Class used to code a single character.
 */
class NeoCharacter {
public:
    /// Limits. in pixels
    static constexpr size_t minWidth = 1;
    static constexpr size_t maxWidth = 128;
    static constexpr size_t minHeight = 1;
    static constexpr size_t maxHexght = 66;

    NeoCharacter();
    NeoCharacter(const NeoCharacter &) = default;
    NeoCharacter(NeoCharacter &&) = default;
    NeoCharacter &operator=(const NeoCharacter &) = default;
    NeoCharacter &operator=(NeoCharacter &&) = default;
    ~NeoCharacter();

    [[nodiscard]] int width() const;
    [[nodiscard]] int height() const;

    int setWidth(int w);
    int setHeight(int h);

    void clear();

    [[nodiscard]] int getPixel(int x, int y) const;
    void setPixel(int x, int y);
    void clearPixel(int x, int y);
    void flipPixel(int x, int y);
    void changePixel(int x, int y, int v);

    void transformTranslate(int dx, int dy);
    void transformFlipV();
    void transformFlipH();
    void transformBold();

    unsigned int archiveSize() const;
    void loadArchive(const uint8_t *data);
    void saveArchive(uint8_t *data) const;

private:
    /* Do not use pointer member variables here. The loadArchive() and
     * saveArchive() methods both in this class and in NeoFont have a trivial
     * implementation that will need to be significantly more complex if
     * pointers are used.
     */

    // In pixels:
    int m_width = 8;
    int m_height = 8;

    // Bitmap of character data. This is treated as an array of pixels, one bit
    // per pixel.
    std::array<uint8_t, ((maxWidth * maxHexght) + 7) / 8> m_bitmap = {};
};
