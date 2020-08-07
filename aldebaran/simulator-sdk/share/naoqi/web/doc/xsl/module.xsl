<?xml version="1.0"?>
<!--
this stylesheet generates the blue documentation from modules xml description
-->
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
		xmlns="http://www.w3.org/1999/xhtml"
		version="1.0">
  <xsl:output method="xml" encoding="utf-8"
	      doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd"
	      doctype-public="-//W3C//DTD XHTML 1.0 Strict//EN"/>

  <xsl:include href="toc.xsl"/>
  <xsl:param name="rootdir"></xsl:param>
  <xsl:param name="mode"/>
  <xsl:param name="productName">Nao68</xsl:param>
  <xsl:variable name="fext">
    <xsl:choose>
      <xsl:when test="$mode='site'">html</xsl:when>
      <xsl:otherwise>xml</xsl:otherwise>
    </xsl:choose>
  </xsl:variable>

  <!-- associates with each method, the module where it s defined -->
  <xsl:key name="methods" match="method" use="string(modulename)"/>

  <!-- main template for page -->
  <xsl:template match="/page">
    <html xml:lang="en" lang="en">
      <head>
	<meta http-equiv="content-type" content="text/html; charset=utf-8" />
	<meta name="Copyright" content="Copyright 2008 Aldebaran-Robotics. All Rights Reserved." />
	<title>
	  <xsl:value-of select="pagetitle"/>
	</title>
	<link rel="stylesheet" type="text/css" href="css/toc.css" />
	<link rel="stylesheet" type="text/css" href="css/modules.css" />
	<link rel="stylesheet" type="text/css" href="css/blue.css" />

	<script type="text/javascript" language="JavaScript" src="JavaScript/module.js">

	</script>
	<xsl:comment><![CDATA[[if lte IE 6]>
	<link rel="stylesheet" type="text/css" href="]]><xsl:value-of select="$rootdir"/><![CDATA[CSS/iefix.css" />
	<![endif]]]></xsl:comment>
      </head>
      <body bgcolor="#FFFFFF">
      <div id="top">
      <div id="logo">
        <p>
          <a href="/">
            <img src="http://www.aldebaran-robotics.com/images/docbleu_logo.png" width="200" height="53" title="Logo" align="left" border="0" alt="Aldebaran"/>
          </a>
        </p>
      </div>
      <div >
        <p>
          <img src="http://www.aldebaran-robotics.com/images/docbleu_nao_logo_quad.png" width="72" height="60" title="Logo" align="right" border="0" alt="NAO" style="margin-right: 10px" />
        </p>
      </div>
    </div>
    <div class="site">

	<div id="tocMenu">
	 <xsl:apply-templates select="self::page" mode="toc"/>
	</div>

	<div id="pageContent">
	  <div id="headerText">
	  </div>

	  <div id="bodyText">
	    <p>
          <a name="{content/module/name}Reference" title="{content/module/name} Reference"></a>
        </p>
	    <a name="{content/module/name}_Reference" title="{content/module/name} Reference" id="{content/module/name}_Reference"></a>
	    <br/>
	    <xsl:apply-templates select="content/module"/>

	    <xsl:if test="examples/example">
	      <h2>
		<a name="examplesCodes" title="examplesCodes" id="examplesCodes"></a>
		<br/>
		<xsl:text>Example Code</xsl:text>
	      </h2>
	      <xsl:apply-templates select="examples/example"/>
	    </xsl:if>

	    <hr />
	    <div id="footerText">
		Copyright © 2011 Aldebaran Robotics - All rights reserved<br />
	    </div>
	  </div>
	</div>

    </div>
    <div id="bluebar"></div>
      </body>
    </html>
  </xsl:template>

  <xsl:template match="alcontext/alpath/allink">
    <xsl:if test="preceding-sibling::allink">
      <xsl:text> &gt; </xsl:text>
    </xsl:if>
    <a href="{alhref}.{$fext}">
      <xsl:value-of select="alname"/>
    </a>
  </xsl:template>

  <!-- generates the body of the page -->
  <xsl:template match="module">

    <!-- title -->
    <a name="Overview" >
    <h1>Overview</h1></a>
    <!-- Description part -->
    <p><xsl:apply-templates select="description/text()"/></p>
    <p class="modVersion">Current version : <xsl:value-of select="version"/></p>

    <h2> Warning </h2>
    <p>
       This doc is deprecated, please use
       <a href="http://aldebaran-robotics.com/documentation/naoqi/index.html">
        <span style="color:#0000BF"> the online Aldebaran documentation </span>
       </a>
       instead.
    </p>

    <!-- local methods -->
    <xsl:if test="count(key('methods',string(name)))">
      <h2>
	<a name="Methods" title="Methods" id="Methods"></a>
	<xsl:text>Methods</xsl:text>
      </h2>
      <xsl:apply-templates select="key('methods',string(name))"/>
    </xsl:if>

    <!-- inherited methods -->
    <xsl:for-each select="methods/method[not(modulename=/page/content/module/name)]">
      <xsl:if test="generate-id()=generate-id(key('methods',modulename)[1])">
	<h2>
	  <a name="Methods_{modulename}" title="Methods_{modulename}" id="Methods_{modulename}"></a>
	  <br/>
	  <xsl:text>Methods inherited from </xsl:text>
	  <xsl:value-of select="modulename"/>
	</h2>
	<xsl:apply-templates select="key('methods',string(modulename))"/>
      </xsl:if>
    </xsl:for-each>

    <!-- examples of code -->
    <xsl:if test="examples/example">
      <h2>
	<a name="examplesCodes" title="examplesCodes" id="examplesCodes"></a>
	<br/>
	<xsl:text>Example Code</xsl:text>
      </h2>
      <xsl:apply-templates select="examples/example"/>
    </xsl:if>

    <!-- Specific page  -->
    <xsl:if test="specificpage">
      <h2>
	<a name="furtherInformation" title="furtherInformation" id="furtherInformation"></a>
	<br/>
	<xsl:text>Further Information</xsl:text>
      </h2>
      <iframe id="specificpage" src="{specificpage}"/>
    </xsl:if>


  </xsl:template>

  <xsl:template match="method">
    <div class="method">
      <a name="{name}" title="{name}" id="{name}"></a>
      <p class="methodProto">
	<span class="methodType"><xsl:value-of select="return/type"/></span>
	<xsl:text> </xsl:text>
	<span class="methodName"><xsl:value-of select="name"/></span>
	<xsl:text> (</xsl:text>
	<xsl:apply-templates select="parameters" mode="inline"/>
	<xsl:text>)</xsl:text>
      </p>
       <p class="methodDesc">
       <xsl:apply-templates select="description/text()"/>
      </p>
      <xsl:if test="parameters/parameter">
	<xsl:apply-templates select="parameters"/>
      </xsl:if>
     <xsl:if test="return/type!='void'">
      <h4>Returns</h4>
        <dl class="termdef">
            <xsl:if test="return/description">
              <dd>
              <p><xsl:apply-templates select="return/description/text()"/></p>
              </dd>
            </xsl:if>
 	    </dl>
   </xsl:if>
      <xsl:if test="examples/example">

	<xsl:apply-templates select="examples/example"/>
      </xsl:if>
    </div>
  </xsl:template>

  <xsl:template match="parameters" mode="inline">
    <xsl:apply-templates select="parameter[1]" mode="inline"/>
    <xsl:for-each select="parameter[not(position()=1)]">
      <xsl:text>, </xsl:text>
      <xsl:apply-templates select="self::parameter" mode="inline"/>
    </xsl:for-each>
  </xsl:template>

  <xsl:template match="parameter" mode="inline">
    <span class="methodType"><xsl:value-of select="type"/></span>
    <xsl:text> </xsl:text>
    <span class="methodArg"><xsl:value-of select="name"/></span>
  </xsl:template>

  <xsl:template match="parameter">
    <dl class="termdef">
      <dt>
	<span class="methodArg"><xsl:value-of select="name"/></span>
      </dt>
      <xsl:if test="description">
	<dd>
	  <p>
        <xsl:apply-templates select="description/text()"/>
      </p>
	</dd>
      </xsl:if>
    </dl>
  </xsl:template>

  <xsl:template match="example">
    <p class="headExample">Example in <xsl:value-of select="language"/> :</p>
    <div class="divExample">
      <pre>
        <xsl:apply-templates select="source/text()"/>
      </pre>
    </div>
  </xsl:template>

  <xsl:template match="text()" name="replaceNL">
    <xsl:param name="pText" select="."/>
    <xsl:choose>
    <xsl:when test="contains($pText, '&#xA;')">
      <xsl:value-of select=
        "substring-before($pText, '&#xA;')"/>
      <br />
      <xsl:call-template name="replaceNL">
        <xsl:with-param name="pText" select=
          "substring-after($pText, '&#xA;')"/>
      </xsl:call-template>
    </xsl:when>
    <xsl:otherwise>
      <xsl:value-of select="$pText"/>
    </xsl:otherwise>
    </xsl:choose>
    </xsl:template>

</xsl:stylesheet>
