//
//  CNMKShape.h
//  cennavimapapi
//
//  Created by Lion on 13-3-19.
//  Copyright (c) 2013年 __CenNavi__. All rights reserved.
//

#import "CNMKOverlay.h"

//...形状基类
@interface CNMKShape : NSObject <CNMKOverlay>
{
    CNMKGeoPoint *_points;
    int _pointCount;
    BOOL _encrypted;
    NSArray *_jamecode;
}

@property (nonatomic) CNMKGeoPoint *points;
@property (nonatomic) NSArray *jamecode;
@property (nonatomic) int pointCount;
@property (nonatomic) BOOL encrypted;

+ (id)shapeWithGeoPoints:(CNMKGeoPoint *)points count:(NSUInteger)count;

@end

//...图形比例尺
@interface CNMKPolyscale : CNMKShape
+ (id)polyscaleWithGeoPoints:(CNMKGeoPoint *)points;

@end

//...折线
@interface CNMKPolyline : CNMKShape
+ (id)polylineWithGeoPoints:(CNMKGeoPoint *)points count:(NSUInteger)count;

@end

//...多边形
@interface CNMKPolygon : CNMKShape
//
+ (id)polygonWithGeoPoints:(CNMKGeoPoint *)points count:(NSUInteger)count;

@end

//...圆
@interface CNMKCircle : CNMKShape
{
    double _radius;
}

@property (nonatomic) double radius;
@property (nonatomic, readonly) CNMKGeoPoint centerCoordinate;

+ (id)circleWithGeoPoint:(CNMKGeoPoint)coordinate radius:(double)radius;

@end