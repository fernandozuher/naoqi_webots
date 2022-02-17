<?xml version="1.0"?>
<!--
this stylesheet generates the blue documentation from broker xml description

-->


<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
		xmlns="http://www.w3.org/1999/xhtml"
		version="1.0">

  <xsl:output method="xml" encoding="utf-8"
	      doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd"
	      doctype-public="-//W3C//DTD XHTML 1.0 Strict//EN"/>

  <xsl:param name="rootdir"></xsl:param>
  <xsl:param name="mode"/>
  <xsl:param name="productName">Nao68</xsl:param>
  <xsl:variable name="fext">
    <xsl:choose>
      <xsl:when test="$mode='site'">html</xsl:when>
      <xsl:otherwise>xml</xsl:otherwise>
    </xsl:choose>
  </xsl:variable>



  <!-- main template for page -->
  <xsl:template match="/page">
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
	<link rel="stylesheet" type="text/css" href="css/broker.css" />
	<link rel="stylesheet" type="text/css" href="css/blue.css" />
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


	  <xsl:apply-templates select="content/broker"/>

	  <div id="footerText">
	    <hr/>
	    <!--
		<p>
		<!- - TODO SB : which date ???? - ->
		  Last updated: <xsl:value-of select="date"/>
		  </p>
	    -->
	    <p>
	      Copyright © 2009 <a href="http://www.aldebaran-robotics.com/" target="_top">Aldebaran Robotics</a><br />
	      All rights reserved
	    </p>
	  </div>
	</div>
      </body>
    </html>
  </xsl:template>


  <!-- generates the body of the page -->

  <xsl:template match="broker">

    <!-- title -->
    <h1 class="btitle">
	<xsl:value-of select="name"/>
	<xsl:text> Broker</xsl:text>
    </h1>

    <xsl:if test="version">
      <p lcass="color">Version: <xsl:value-of select="version"/></p>
    </xsl:if>

    <!-- Parent Broker -->
    <xsl:apply-templates select="parentBroker"/>

    <h2> Warning </h2>
    <p>
      <emph>
       This doc is deprecated, please use
       <a href="http://aldebaran-robotics.com/documentation/naoqi/index.html">
          the online Aldebaran documentation
       </a>
       instead
      </emph>
    </p>

    <!-- tasks -->
    <xsl:choose>
      <xsl:when test="tasks/task">
	<xsl:apply-templates select="tasks"/>
      </xsl:when>
<!--
      <xsl:otherwise>
	<h2 class="color">There are no active tasks</h2>
      </xsl:otherwise>
-->
    </xsl:choose>

    <!-- child Brokers -->
    <xsl:apply-templates select="childBrokers[broker]"/>

    <!-- modules -->
    <xsl:apply-templates select="modules"/>
  </xsl:template>

   <!-- Parent Broker -->
  <xsl:template match="parentBroker">
    <div id="parentBroker">
      <h2>Parent Broker</h2>
      <xsl:apply-templates select="broker[position() mod 3 = 1]" mode="row"/>
    </div>
  </xsl:template>

  <xsl:template match="parentBroker/broker" mode="row">
    <div class="modrow">
      <xsl:apply-templates select="."/>
      <xsl:apply-templates select="following-sibling::broker[1]"/>
      <xsl:apply-templates select="following-sibling::broker[2]"/>
    </div>
  </xsl:template>

  <xsl:template match="parentBroker/broker">
    <a href="http://{href}/index.xml">
      <div class="broker pos{count(preceding-sibling::broker) mod 3}" title="{name}">
	<h3><xsl:value-of select="name"/></h3>
      </div>
    </a>
  </xsl:template>


    <!-- child Brokers -->
   <xsl:template match="childBrokers">
    <div id="childBrokers">
      <h2>Child Brokers</h2>
      <xsl:apply-templates select="broker[position() mod 3 = 1]" mode="row"/>
    </div>
  </xsl:template>

  <xsl:template match="childBrokers/broker" mode="row">
    <div class="modrow">
      <xsl:apply-templates select="."/>
      <xsl:apply-templates select="following-sibling::broker[1]"/>
      <xsl:apply-templates select="following-sibling::broker[2]"/>
    </div>
  </xsl:template>

  <xsl:template match="childBrokers/broker">
    <a href="http://{href}/index.xml">
      <div class="broker pos{count(preceding-sibling::broker) mod 3}" title="{name}">
	<h3><xsl:value-of select="name"/></h3>
      </div>
    </a>
  </xsl:template>



  <xsl:template match="tasks">
    <div id="tasks">
      <h2>Active Tasks</h2>
      <ol>
	<xsl:apply-templates select="task"/>
      </ol>
    </div>
  </xsl:template>

  <xsl:template match="tasks/task">
    <li class="color"><xsl:value-of select="moduleName"/>::<xsl:value-of select="method/name"/> - <xsl:value-of select="method/description"/></li>
  </xsl:template>

  <xsl:template match="modules">
    <h2>Modules</h2>
    <div id="modules">
      <xsl:apply-templates select="module[position() mod 3 = 1]" mode="row"/>
    </div>
  </xsl:template>

  <xsl:template match="module" mode="row">
    <div class="modrow">
      <xsl:apply-templates select="."/>
      <xsl:apply-templates select="following-sibling::module[1]"/>
      <xsl:apply-templates select="following-sibling::module[2]"/>
    </div>
  </xsl:template>

  <xsl:template match="module">
    <a href="{name}.{$fext}">
      <div class="module pos{count(preceding-sibling::module) mod 3}" title="{name}">
	<h3><xsl:call-template name="modname"/></h3>
	<p class="color"><xsl:value-of select="description"/></p>
      </div>
    </a>
  </xsl:template>

  <xsl:template name="modname">
    <xsl:choose>
      <xsl:when test="string-length(name) &lt; 25">
	<xsl:value-of select="name"/>
      </xsl:when>
      <xsl:otherwise>
	<xsl:value-of select="substring(name,0,25)"/>
	<xsl:text>...</xsl:text>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
</xsl:stylesheet>
