/** @file       NeoCharacter.h
 *  @brief      Neo font character object header file.
 *  @copyright  (c) 2006 Alquanto. All Rights Reserved.
 */
#pragma once

#include <array>
#include <cstddef>

/// Limits.
//< Maximum width of a single character, in pixels.
constexpr size_t kNeoCharacterMaxWidth = 128;
//< Minimum width of a single character, in pixels.
constexpr size_t kNeoCharacterMinWidth = 1;
/**< Minimum font height, in pixels. */
constexpr size_t kNeoCharacterMinHeight = 1;
/**< Maximum font height, in pixels. */
constexpr size_t kNeoCharacterMaxHeight = 66;

/** Class used to code a single character.
 */
class NeoCharacter {
public:
    NeoCharacter();
    //    NeoCharacter(const NeoCharacter &other);
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
    int m_width;  /**< Character width, in pixels. */
    int m_height; /**< Character height, in pixels. */

    /** Bitmap of character data. This is treated as an array of pixels, one bit
     * per pixel.
     */
    std::array<uint8_t,
               ((kNeoCharacterMaxWidth * kNeoCharacterMaxHeight) + 7) / 8>
        m_bitmap;
};
