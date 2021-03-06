/*
    RPG Paper Maker Copyright (C) 2017 Marie Laporte

    This file is part of RPG Paper Maker.

    RPG Paper Maker is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    RPG Paper Maker is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef WIDGETTILESETSETTINGS_H
#define WIDGETTILESETSETTINGS_H

#include <QWidget>
#include "systempicture.h"
#include "collisionsquare.h"

// -------------------------------------------------------
//
//  CLASS WidgetTilesetSettings
//
//  Widget used for choosing a setting picture existing in the database.
//
// -------------------------------------------------------

namespace Ui {
class WidgetTilesetSettings;
}

class WidgetTilesetSettings : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetTilesetSettings(QWidget *parent = 0);
    ~WidgetTilesetSettings();
    void setSquares(QHash<QPoint, CollisionSquare*>* squares);
    void updateImage(SystemPicture* picture);
    void updateImageSpecial(QImage& editedImage, SystemPicture* picture);
    void updateImageAutotile(SystemPicture* picture);
    PictureKind kind() const;
    void setKind(PictureKind kind);
    void updateZoom(int zoom);
    void deleteDirectionTab();
    void showRepeat();
    void disableNone(bool b);

private:
    Ui::WidgetTilesetSettings *ui;
    SystemPicture* m_picture;
    PictureKind m_kind;
    float m_zoom;

protected:
    virtual void showEvent(QShowEvent *event);

public slots:
    void on_horizontalSlider_valueChanged(int value);
    void on_checkBoxRepeat_toggled(bool checked);
};

#endif // WIDGETTILESETSETTINGS_H
