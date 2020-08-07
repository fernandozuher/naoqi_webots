<?xml version="1.0"?>
<!--
this stylesheet generates the blue documentation from docbook

-->


<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
		xmlns="http://www.w3.org/1999/xhtml"
		version="1.0">

  <xsl:output method="xml" encoding="utf-8"
	      doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd"
	      doctype-public="-//W3C//DTD XHTML 1.0 Strict//EN"/>

  <xsl:include href="toc-docbook.xsl"/>
  <xsl:param name="rootdir">../</xsl:param>
  <xsl:param name="type"><xsl:value-of select="/*/@role"/></xsl:param>
  <xsl:param name="docid"><xsl:value-of select="/*/@id"/></xsl:param>
  <xsl:param name="mode"/>

  <xsl:variable name="indexfile" select="document('../index.xml')"/>
  <xsl:variable name="parenttitle"><xsl:value-of select="$indexfile/directory/title"/></xsl:variable>
  <xsl:variable name="parentdesc"><xsl:value-of select="$indexfile/directory/description"/></xsl:variable>
  <xsl:variable name="prevtitle"><xsl:value-of select="$indexfile/directory/content/file[@name=$docid]/preceding-sibling::file[1]/title"/></xsl:variable>
  <xsl:variable name="prevdesc"><xsl:value-of select="$indexfile/directory/content/file[@name=$docid]/preceding-sibling::file[1]/description"/></xsl:variable>
  <xsl:variable name="previd"><xsl:value-of select="$indexfile/directory/content/file[@name=$docid]/preceding-sibling::file[1]/@name"/></xsl:variable>
  <xsl:variable name="nexttitle"><xsl:value-of select="$indexfile/directory/content/file[@name=$docid]/following-sibling::file[1]/title"/></xsl:variable>
  <xsl:variable name="nextdesc"><xsl:value-of select="$indexfile/directory/content/file[@name=$docid]/following-sibling::file[1]/description"/></xsl:variable>
  <xsl:variable name="nextid"><xsl:value-of select="$indexfile/directory/content/file[@name=$docid]/following-sibling::file[1]/@name"/></xsl:variable>

  <xsl:variable name="fext">
    <xsl:choose>
      <xsl:when test="$mode='site'">html</xsl:when>
      <xsl:otherwise>xml</xsl:otherwise>
    </xsl:choose>
  </xsl:variable>


  <xsl:param name="productName">Nao68</xsl:param>

  <!-- associates with each method, the module where it s defined -->
  <xsl:key name="methods" match="method" use="string(modulename)"/>

  <!-- main template for page -->
  <xsl:template match="article|chapter|preface|appendix|partintro">
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
	<link rel="stylesheet" type="text/css" href="{$rootdir}CSS/toc.css" />
	<link rel="stylesheet" type="text/css" href="{$rootdir}CSS/manual.css" />
	<xsl:choose>
	  <xsl:when test="$type='reddoc'">
	    <link rel="stylesheet" type="text/css" href="{$rootdir}CSS/red.css" />
	  </xsl:when>
	  <xsl:when test="$type='greendoc'">
	    <link rel="stylesheet" type="text/css" href="{$rootdir}CSS/green.css" />
	  </xsl:when>
	</xsl:choose>
	<script type="text/javascript" language="JavaScript" src="{$rootdir}JavaScript/module.js">
	</script>
	<xsl:comment><![CDATA[[if lte IE 6]>
	<link rel="stylesheet" type="text/css" href="]]><xsl:value-of select="$rootdir"/><![CDATA[CSS/iefix.css" />
	<![endif]]]></xsl:comment>
      </head>
      <body bgcolor="#FFFFFF">
	<div id="tocMenu">
	  <xsl:apply-templates select="self::*" mode="toc"/>
	</div>

	<div id="pageContent">
	  <div id="headerText">
	    <p>
	      <span id="PNUS" class="mini_nav_text">
		<xsl:if test="$previd!=''">
		  <a href="{$previd}.{$fext}" title="{$prevdesc}">
		    <xsl:text>&lt;&lt; </xsl:text>
		    <xsl:value-of select="$prevtitle"/>
		  </a>
		</xsl:if>
		<xsl:text> | </xsl:text>
		<xsl:if test="$nextid!=''">
		  <a href="{$nextid}.{$fext}" title="{$nextdesc}">
		    <xsl:value-of select="$nexttitle"/>
		    <xsl:text> &gt;&gt;</xsl:text>
		  </a>
		</xsl:if>
	      </span>
	      <span id="TOCUS" class="mini_nav_text">
		<a id="hideTOCUpperSpan" href="#" onclick="showHideTOC();">Hide TOC</a>
		<a id="showTOCUpperSpan" href="#" onclick="showHideTOC();">Show TOC</a>
	      </span>
	      <span id="breadcrumb" class="breadcrumb">
		<a href="index.{$fext}" title="{$parentdesc}" target="_self"><xsl:value-of select="$parenttitle"/></a>
	      </span>

	    </p>
	  </div>
	  <xsl:apply-templates>
	    <xsl:with-param name="oid" select="local-name()"/>
	  </xsl:apply-templates>

	  <div id="footerText">
	    <hr/>
	    <p>
	      Copyright © 2008 Aldebaran-robotics.<br />
	      <a href="http://www.aldebaran-robotics.com/" target="_top">All rights reserved.</a>
	    </p>
	  </div>
	</div>
      </body>
    </html>
  </xsl:template>


  <!-- **************************************************************************** -->
  <!-- Sections -->
  <xsl:template match="section|simplesect|sect1|sect2|sect3|sect4|sect5">
    <div class="section">
      <a name="{generate-id()}" title="{generate-id()}" id="{generate-id()}"></a>
      <xsl:if test="@id">
	<a name="{@id}" title="{@id}" id="{@id}"></a>
      </xsl:if>
      <xsl:apply-templates/>
    </div>
  </xsl:template>



  <!-- **************************************************************************** -->
  <!-- titles -->

  <xsl:template match="title/@id">
    <a name="{.}" title="{.}" id="{.}"></a>
  </xsl:template>


  <xsl:template match="section/title">
    <xsl:variable name="level" select="1+count(ancestor::section)"/>
    <xsl:element name="h{$level}">
      <xsl:apply-templates select="node()|@*"/>
    </xsl:element>
  </xsl:template>

  <xsl:template match="simplesect/title">
    <xsl:variable name="level" select="1+count(ancestor::sect1|ancestor::sect2|ancestor::sect3|ancestor::sect4|ancestor::sect5)"/>
    <xsl:element name="h{$level}">
      <xsl:apply-templates select="node()|@*"/>
    </xsl:element>
  </xsl:template>

  <xsl:template match="article/title">
    <h1><xsl:apply-templates select="node()|@*"/></h1>
  </xsl:template>

  <xsl:template match="sect1/title">
    <h2><xsl:apply-templates select="node()|@*"/></h2>
  </xsl:template>

  <xsl:template match="sect2/title">
    <h3><xsl:apply-templates select="node()|@*"/></h3>
  </xsl:template>

  <xsl:template match="sect3/title">
    <h4><xsl:apply-templates select="node()|@*"/></h4>
  </xsl:template>

  <xsl:template match="sect4/title">
    <h5><xsl:apply-templates select="node()|@*"/></h5>
  </xsl:template>

  <xsl:template match="sect5/title">
    <h6><xsl:apply-templates select="node()|@*"/></h6>
  </xsl:template>

  <xsl:template match="sect5/title">
    <h6><xsl:apply-templates select="node()|@*"/></h6>
  </xsl:template>

  <xsl:template match="formalpara/title">
    <p class="runin title"><xsl:apply-templates select="node()|@*"/></p>
  </xsl:template>

  <xsl:template match="subtitle">
    <p class="subtitle"><xsl:apply-templates select="node()|@*"/></p>
  </xsl:template>


  <!-- **************************************************************************** -->
  <!-- block level elements -->
  <!-- (CalloutList|GlossList|ItemizedList|OrderedList|SegmentedList|
  SimpleList|VariableList|Caution|Important|Note|Tip|Warning|
  LiteralLayout|ProgramListing|ProgramListingCO|Screen|ScreenCO|
  ScreenShot|Synopsis|CmdSynopsis|FuncSynopsis|FormalPara|Para|
  SimPara|Address|BlockQuote|Graphic|GraphicCO|MediaObject|
  MediaObjectCO|InformalEquation|InformalExample|InformalFigure|
  InformalTable|Equation|Example|Figure|Table|MsgSet|Procedure|
  Sidebar|QandASet|Anchor|BridgeHead|Comment|Highlights|
  Abstract|AuthorBlurb|Epigraph|IndexTerm)  -->

  <xsl:template match="@*"/>


  <xsl:template match="para|simpara">
    <p>
      <xsl:apply-templates select="node()|@*"/>
    </p>
  </xsl:template>

  <xsl:template match="formalpara">
    <div class="{local-name()}">
      <xsl:apply-templates select="node()|@*"/>
    </div>
  </xsl:template>

  <xsl:template match="itemizedlist|calloutlist">
    <ul>
      <xsl:apply-templates select="node()|@*"/>
    </ul>
  </xsl:template>

  <!-- list elements -->

  <xsl:template match="orderedlist">
    <ol>
      <xsl:apply-templates select="node()|@*"/>
    </ol>
  </xsl:template>

  <xsl:template match="listitem">
    <li>
      <xsl:apply-templates select="node()|@*"/>
    </li>
  </xsl:template>

  <xsl:template match="glosslist">
    <dl>
      <xsl:apply-templates select="node()|@*"/>
    </dl>
  </xsl:template>

  <xsl:template match="glossentry">
    <dt>
      <xsl:apply-templates select="glossterm|acronym|abbrev"/>
    </dt>
    <dd>
      <xsl:apply-templates select="glosssee|glossdef"/>
    </dd>
  </xsl:template>

  <xsl:template match="segmentedlist">
    <dl>
      <xsl:for-each select="segtitle">
	<xsl:variable name="pos">
	  <xsl:value-of select="position()"/>
	</xsl:variable>
	<xsl:apply-templates select="self::segtitle"/>
	<dd>
	  <ul>
	    <xsl:for-each select="../sellistitem[position()=$pos]/seg">
	      <xsl:apply-templates select="self::seg"/>
	    </xsl:for-each>
	  </ul>
	</dd>
      </xsl:for-each>
    </dl>
  </xsl:template>

  <xsl:template match="segtitle">
    <dt><xsl:apply-templates select="node()|@*"/></dt>
  </xsl:template>

  <xsl:template match="seg">
    <li><xsl:apply-templates select="node()|@*"/></li>
  </xsl:template>

  <xsl:template match="simplelist">
    <span class="{local-name()}">
      <xsl:apply-templates select="@*"/>
      <xsl:apply-templates select="member"/>
    </span>
  </xsl:template>

  <xsl:template match="member">
    <span class="{local-name()}">
      <xsl:if test="not(position()=1) and parent::simplelist[@type='inline']">
	<xsl:text>, </xsl:text>
      </xsl:if>
      <xsl:apply-templates select="node()|@*"/>
    </span>
  </xsl:template>

<!-- Images -->

  <xsl:template match="mediaobject">
    <div class="illustration">
      <xsl:apply-templates select="node()|@*"/>
    </div>
  </xsl:template>

  <xsl:template match="inlinemediaobject">
    <span class="illustration">
      <xsl:apply-templates select="node()|@*"/>
    </span>
  </xsl:template>

  <xsl:template match="imageobject">
    <img src="{imagedata/@fileref}" alt="{../caption}" title="{../caption}">
      <xsl:if test="imagedata/@contentwidth">
	<xsl:attribute name="width"><xsl:value-of select="imagedata/@contentwidth"/></xsl:attribute>
      </xsl:if>
      <xsl:if test="imagedata/@contentdepth">
	<xsl:attribute name="height"><xsl:value-of select="imagedata/@contentdepth"/></xsl:attribute>
      </xsl:if>
    </img>
  </xsl:template>

  <xsl:template match="mediaobject/caption">
    <div class="caption">
      <span class="captionNumber"><xsl:number count="mediaobject/caption" level="any"/></span>
      <xsl:apply-templates select="node()|@*"/>
    </div>
  </xsl:template>


<!-- function synopsis -->

  <xsl:template match="funcsynopsis">
    <div class="synopsis">
      <xsl:apply-templates select="node()|@*"/>
    </div>
  </xsl:template>

  <xsl:template match="funcprototype">
    <p class="methodProto">
      <xsl:apply-templates select="funcdef"/>
      <xsl:text> (</xsl:text>
      <xsl:apply-templates select="paramdef"/>
      <xsl:text>)</xsl:text>
    </p>
  </xsl:template>

  <xsl:template match="funcdef">
    <span class="methodType"><xsl:apply-templates select="text()"/></span>
    <xsl:text> </xsl:text>
    <span class="methodName"><xsl:apply-templates select="function"/></span>
  </xsl:template>

  <xsl:template match="paramdef[1]" name="paramdef">
    <span class="methodType"><xsl:apply-templates select="text()"/></span>
    <xsl:text> </xsl:text>
    <span class="methodArg"><xsl:apply-templates select="parameter"/></span>
  </xsl:template>

  <xsl:template match="paramdef">
    <xsl:text>, </xsl:text>
    <xsl:call-template name="paramdef"/>
  </xsl:template>


  <!-- address - literallayout - programlisting screen screenshot synopsis -->
  <xsl:template match="programlisting">
    <div class="programlisting">
      <pre>
	<xsl:apply-templates select="node()|@*"/>
      </pre>
    </div>
  </xsl:template>
  <!-- Admonitions -->

  <xsl:template match="tip|note|caution|important|warning">
    <div class="{local-name()} framed">
      <xsl:apply-templates select="node()|@*"/>
    </div>
  </xsl:template>

  <!-- example informalexemple figure informalfigure table informaltable -->
  <!-- equation informalequation -->
  <!-- qandaset -->
  <!-- blockquote cmdsysnopsis epigraph funcsynonpsis hightlights msgset procedure sidebar -->


  <!-- **************************************************************************** -->
  <!-- Inline Elements -->

  <!-- publishing -->
  <xsl:template match="abbrev|acronym|emphasis|footnote|phrase|quote|trademark">
    <span class="inline_publishing {local-name()}"><xsl:apply-templates select="node()|@*"/></span>
  </xsl:template>

  <!-- crossref -->
  <xsl:template match="anchor|citation|citerefentry|citetitle|firstterm|glossterm|olink|xref">
    <span class="inline_xref {local-name()}"><xsl:apply-templates select="node()|@*"/></span>
  </xsl:template>


  <xsl:template match="link">
    <a  class="inline_xref link internal"><xsl:apply-templates select="node()|@*"/></a>
  </xsl:template>

  <xsl:template match="link/@linkend">
    <xsl:attribute name="href">
      <xsl:text>#</xsl:text>
      <xsl:value-of select="."/>
    </xsl:attribute>
  </xsl:template>

  <xsl:template match="ulink">
    <a class="inline_xref ulink external"><xsl:apply-templates select="node()|@*"/></a>
  </xsl:template>

  <xsl:template match="ulink/@url">
    <xsl:attribute name="href">
      <xsl:value-of select="."/>
    </xsl:attribute>
  </xsl:template>

  <xsl:template match="foreignphrase|wordasword|computeroutput|literal|markup|prompt|replaceable|sgmltag|userinput">
    <span class="inline_markup {local-name()}"><xsl:apply-templates select="node()|@*"/></span>
  </xsl:template>


  <xsl:template match="accel|guibutton|guiicon|guilabel|guimenu|guimenuitem|guisubmenu|keycap|keycode|keycombo|keysym|menuchoice|mousebutton|shortcut">
    <span class="inline_ui {local-name()}"><xsl:apply-templates select="node()|@*"/></span>
  </xsl:template>


 <xsl:template match="action|classname|constant|errorcode|errorname|errortype|function|interface|interfacedefinition|lteral|mgtext|parameter|property|replaceable|returnvalue|structfield|structName|symbol|token|type|varname">
    <span class="inline_prog {local-name()}"><xsl:apply-templates select="node()|@*"/></span>
 </xsl:template>


 <xsl:template match="application|command|envar|filename|medialabel|msgtext|option|parameter|prompt|systemitem">
    <span class="inline_syst {local-name()}"><xsl:apply-templates select="node()|@*"/></span>
 </xsl:template>

 <xsl:template match="database|email|filename|hardware|inlinegraphic|medialabel|optional">
    <span class="inline_misc {local-name()}"><xsl:apply-templates select="node()|@*"/></span>
 </xsl:template>

 <xsl:template match="inlineequation">
   <span class="inline_math {local-name()}"><xsl:apply-templates select="node()|@*"/></span>
 </xsl:template>

 <xsl:template match="subscript">
   <sub><xsl:apply-templates select="node()|@*"/></sub>
 </xsl:template>

 <xsl:template match="superscript">
   <sup><xsl:apply-templates select="node()|@*"/></sup>
 </xsl:template>




  <!-- **************************************************************************** -->
  <!-- Table Elements -->

  <xsl:template match="table">
    <table class="formaltable">
      <xsl:apply-templates/>
    </table>
  </xsl:template>

  <xsl:template match="informaltable">
    <div class="informaltable">
      <table>
	<xsl:apply-templates select="node()|@*"/>
      </table>
    </div>
  </xsl:template>

  <xsl:template match="table/caption|table/title">
    <caption class="tablecaption"><xsl:apply-templates select="node()|@*"/></caption>
    <!--
    <div class="tablecaption">
      <xsl:apply-templates select="node()|@*"/>
    </div>
    -->
  </xsl:template>

  <xsl:template match="tgroup">
    <table>
      <xsl:apply-templates select="node()|@*"/>
    </table>
  </xsl:template>

  <xsl:template match="thead">
    <thead>
      <xsl:apply-templates select="node()|@*"/>
    </thead>
  </xsl:template>

  <xsl:template match="tfoot">
    <tfoot>
      <xsl:apply-templates select="node()|@*"/>
    </tfoot>
  </xsl:template>


  <xsl:template match="tbody">
    <tbody>
      <xsl:apply-templates select="node()|@*"/>
    </tbody>
  </xsl:template>

  <xsl:template match="td/@colspan|th/@colspan|td/@rowspan|th/@rowspan">
    <xsl:copy/>
  </xsl:template>

  <xsl:template match="row|tr">
    <tr>
      <xsl:apply-templates select="node()|@*"/>
    </tr>
  </xsl:template>

  <xsl:template match="entry|td">
    <td>
      <xsl:apply-templates select="node()|@*"/>
    </td>
  </xsl:template>


  <xsl:template match="thead/row/entry|th">
    <th>
      <xsl:apply-templates select="node()|@*"/>
    </th>
  </xsl:template>

</xsl:stylesheet>
