/*
 * SegmentList.cpp
 *****************************************************************************
 * Copyright (C) 2010 - 2012 Klagenfurt University
 *
 * Created on: Jan 27, 2012
 * Authors: Christopher Mueller <christopher.mueller@itec.uni-klu.ac.at>
 *          Christian Timmerer  <christian.timmerer@itec.uni-klu.ac.at>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#include "SegmentList.h"
#include "Segment.h"
#include "SegmentInformation.hpp"

using namespace adaptative::playlist;

SegmentList::SegmentList( SegmentInformation *parent ):
    SegmentInfoCommon( parent ), TimescaleAble( parent )
{
}
SegmentList::~SegmentList()
{
    std::vector<Segment *>::iterator it;
    for(it = segments.begin(); it != segments.end(); ++it)
        delete(*it);
}

const std::vector<Segment*>& SegmentList::getSegments() const
{
    return segments;
}

void SegmentList::addSegment(Segment *seg)
{
    segments.push_back(seg);
}
