<?xml version="1.0" encoding="utf-8"?>


<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
		xmlns="http://www.w3.org/1999/xhtml"
		version="1.0">

  <xsl:output method="xml" encoding="utf-8"
	      doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd"
	      doctype-public="-//W3C//DTD XHTML 1.0 Strict//EN"/>

  <xsl:param name="rootdir">../</xsl:param>
  <xsl:param name="type"><xsl:value-of select="/*/@type"/></xsl:param>
  <xsl:param name="mode"/>
  <xsl:param name="productName">Nao68</xsl:param>
  <xsl:variable name="fext">
    <xsl:choose>
      <xsl:when test="$mode='site'">html</xsl:when>
      <xsl:otherwise>xml</xsl:otherwise>
    </xsl:choose>
  </xsl:variable>

  <xsl:template match="/directory">
    <html xml:lang="en" lang="en">
      <head>
	<meta http-equiv="content-type" content="text/html; charset=utf-8" />
	<meta name="Copyright" content="Copyright 2008 Aldebaran-Robotics. All Rights Reserved." />
	<!--
	<meta id="toc-file" name="toc-file" content="almotion_toc.html" />
	-->
	<title>
	  Aldebaran-Robotics Application Interface
	</title>
	<link rel="stylesheet" type="text/css" href="{$rootdir}/CSS/broker.css" />
	<xsl:choose>
	  <xsl:when test="$type='reddoc'">
	    <link rel="stylesheet" type="text/css" href="{$rootdir}/CSS/red.css" />
	  </xsl:when>
	  <xsl:when test="$type='greendoc'">
	    <link rel="stylesheet" type="text/css" href="{$rootdir}/CSS/green.css" />
	  </xsl:when>
	</xsl:choose>
	<xsl:comment><![CDATA[[if lte IE 7]>
	<link rel="stylesheet" type="text/css" href="]]><xsl:value-of select="$rootdir"/><![CDATA[CSS/iefix.css" />
	<![endif]]]></xsl:comment>
      </head>
      <body bgcolor="#FFFFFF" id="brokerbodypage">
	<div id="squares">
	  <div class="square sq1"> </div>
	  <div class="square sq2"> </div>
	  <div class="square sq3"> </div>
	  <div class="square sq4"> </div>
	  <div class="square sq5"> </div>
	  <div class="square sq6"> </div>
	  <div class="square sq7"> </div>
	</div>
	<div id="bodyText">
	  <!-- title -->
	  <h1 class="btitle">
	    <xsl:value-of select="title"/>
	  </h1>
	  <p class="color"><xsl:value-of select="description"/></p>
	  <xsl:if test="version">
  	    <p class="color">Version: <xsl:value-of select="version"/></p>
  	  </xsl:if>
	  <xsl:apply-templates select="content"/>

	<div id="footerText">
	  <hr/>
	  <!--
	      <p>
	      <!- - TODO SB : which date ???? - ->
	      Last updated: <xsl:value-of select="date"/>
	      </p>
	  -->
	  <p>
	    Copyright © 2008 Aldebaran-robotics.<br />
	    <a href="http://www.aldebaran-robotics.com/" target="_top">All rights reserved.</a>
	  </p>
	</div>
	</div>
      </body>
    </html>
  </xsl:template>

  <xsl:template match="content">
    <div id="modules">
      <xsl:apply-templates select="file[position() mod 3 = 1]" mode="row"/>
    </div>
  </xsl:template>

  <xsl:template match="file" mode="row">
    <div class="modrow">
      <xsl:apply-templates select="."/>
      <xsl:apply-templates select="following-sibling::file[1]"/>
      <xsl:apply-templates select="following-sibling::file[2]"/>
    </div>
  </xsl:template>

  <xsl:template match="file">
    <a href="{@name}.{$fext}">
      <div class="broker pos{count(preceding-sibling::file) mod 3}" title="{title}">
	<h3><xsl:value-of select="title"/></h3>
	<p class="color"><xsl:value-of select="description"/></p>
      </div>
    </a>
  </xsl:template>



</xsl:stylesheet>
