/************************************************************************************************
*																								*
*					IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.			*
*																								*
*	By downloading, copying, installing or using the software you agree to this license.		*
*	If you do not agree to this license, do not download, install, copy or use the software.	*
*																								*
*									License Agreement											*
*                			For Vision Open Statistical Models									*
*																								*
* Copyright (C):    2006~2011 by JIA Pei, all rights reserved.									*
*																								*
*    				VOSM is free software under the terms of the GNU Lesser General Public 		*
*					License (GNU LGPL) as published by the Free Software Foundation; 			*
*					either version 3.0 of the License, or (at your option) any later version.	*
* 					You can use it, modify it, redistribute it, etc; and redistribution and 	*
*					use in source and binary forms, with or without	modification, are permitted *
*					provided that the following conditions are met: 							*
*																								*
*					a) Redistribution's of source code must retain this whole paragraph of		*
*					copyright notice, including this list of conditions and all the following 	*
*					contents in this copyright paragraph.										*
*																								*
* 					b) Redistribution's in binary form must reproduce this whole paragraph of	*
*					copyright notice, including this list of conditions and all the following 	*
*					contents in this copyright paragraph, and/or other materials 				*
*					provided with the distribution.												*
*																								*
*					c) The name of the copyright holders may not be used to endorse or 			*
*					promote products derived from this software without specific prior 			*
*					written permission.															*
*																								*
* 					Any publications based on this code must cite the following five			*
*					papers, technic reports and on-line materials.								*
*					1) P. JIA, 2D Statistical Models, Technical Report of Vision Open 			*
*					Working Group, 2st Edition, Oct 21, 2010. 									*
*					http://www.visionopen.com/members/jiapei/publications/pei_sm2dreport2010.pdf*
* 					2) P. JIA. Audio-visual based HMI for an Intelligent Wheelchair.			*
* 					PhD thesis, University of Essex, 2010.										*
* 					http://www.visionopen.com/members/jiapei/publications/pei_phdthesis2010.pdf *
*					3) T. Cootes and C. Taylor. Statistical models of appearance for computer	*
*					vision. Technical report, Imaging Science and Biomedical Engineering,		*
*					University of Manchester, March 8 2004.										*
*					4) I. Matthews and S. Baker. Active appearance models revisited.			*
*					International Journal of Computer Vision, 60(2):135–164, November 2004.		*
*					5) M. B. Stegmann, Active Appearance Models: Theory, Extensions and Cases,	*
*					http://www2.imm.dtu.dk/~aam/main/, 2000										*
* 																								*
* Version:          0.3                                                     					*
* Author:           JIA Pei                                                 					*
* Contact:          jp4work@gmail.com                                       					*
* URL:              http://www.visionopen.com                               					*
* Create Date:      2010-11-04                                             						*
*************************************************************************************************/

#ifndef __TRACKINGALGS_H__
#define __TRACKINGALGS_H__


#include "cv.h"
#include "highgui.h"
#include "VO_CVCommon.h"

using namespace std;
using namespace cv;


/** 
 * @author		JIA Pei
 * @brief		Object tracking algorithms, unlike CDetectionAlgs, CTrackingAlgs
 * 				can deal with only 1 concerned object but not for multiple objects.
 */
class CTrackingAlgs
{
friend class CLocalizationAlgs;
protected:
	/** Tracked object rectangle */
	Rect 						m_CVTrackedObjectRect;

	/** Tracking Method */
	unsigned int				m_iTrackingMethod;

	/** Tracker Method */
	unsigned int				m_iTrackerMethod;
	
	/** Whether the tracker has been initialized */
	bool						m_bTrackerInitialized;
	
	/** Whether the objects is tracked */
    bool                		m_bObjectTracked;
	
	/** Initialization */
	void						init(unsigned int trackingmtd, unsigned int trackermtd);

public:
	enum { PROBABILITYIMAGE = 1};
	enum { NONE = 0, CAMSHIFT = 1, KALMANFILTER = 2, PARTICLEFILTER = 3, ASMAAM = 4};

	CTrackingAlgs(unsigned int trackingmtd = CTrackingAlgs::CAMSHIFT, unsigned int trackermtd = CTrackingAlgs::PROBABILITYIMAGE);
	~CTrackingAlgs();

	void						SetConfiguration(unsigned int trackingmtd = CTrackingAlgs::CAMSHIFT,
												unsigned int trackermtd = CTrackingAlgs::PROBABILITYIMAGE)
	{
								this->m_iTrackingMethod = trackingmtd;
								this->m_iTrackerMethod	= trackermtd;
	}

	void						UpdateTracker(const Mat& img, const Rect& obj);

	double						Tracking( 	const Mat& img,
											Rect& obj,
											Size smallSize = Size(FACESMALLESTSIZE, FACESMALLESTSIZE),
											Size bigSize = Size(FACEBIGGESTSIZE, FACEBIGGESTSIZE));

	static bool					CamshiftUpdateTracker(const Mat& img, const Rect& obj, MatND& hist);

	static double				CamshiftTracking( 	const Mat& img,
													MatND& hist,
													Rect& obj,
													bool& isTracked,
													Size smallSize,
													Size bigSize);

	static double				KalmanTracking(	const Mat& img,
												Rect& obj,
												bool& isTracked,
												Size smallSize,
												Size bigSize);

	static double				ParticleFilterTracking(	const Mat& img,
														Rect& obj,
														bool& isTracked,
														Size smallSize,
														Size bigSize);

	static double				ASMAAMTracking( const Mat& img,
												Rect& obj,
												bool& isTracked,
												Size smallSize,
												Size bigSize);

	/** Draw all detected objects on the image */
	void                        VO_DrawTracking(Mat& ioImg, Scalar color = colors[6]);

	/** Are objects tracked? */
	bool						IsObjectTracked() const {return this->m_bObjectTracked; }

	/** Return tracked objects rectangles */
	Rect 						GetTrackedObjectRect() const { return this->m_CVTrackedObjectRect; }

	static const int			vmin = 10;
	static const int			vmax = 256;
	static const int			smin = 30;
	static const int			hbins = 32;				// quantize the hue to 32 levels
	static const int			sbins = 32;				// quantize the saturation to 32 levels
	static int					histSize[] ;
	static float				hranges[];
	static float				sranges[];
	static const float*			ranges[];
	static int 					channels[];

	MatND						m_hist;
};

#endif	// __TRACKINGALGS_H__
