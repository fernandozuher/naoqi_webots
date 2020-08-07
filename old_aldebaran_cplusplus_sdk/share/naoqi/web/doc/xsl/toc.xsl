<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
		xmlns="http://www.w3.org/1999/xhtml"
		version="1.0">

  <xsl:output method="xml" encoding="utf-8"
	      doctype-public="-//W3C//DTD HTML 4.01 Transitional//EN"/>


  <xsl:template match="/page" mode="toc">
    <div id="toc">
    <span class="breadcrumb"><a href="/" target="_top">Home</a> &gt;&gt; <a href="/" target="_top">Documentation</a></span>
      <a href="#Overview">
        <h2 title="{content/module/name}" class="level0"><span id="bluearrow">&gt;</span><xsl:value-of select="content/module/name"/></h2></a>

      <div id="toccontent">
	<xsl:apply-templates select="content/module" mode="toc"/>
      </div>
    </div>
  </xsl:template>

  <xsl:template match="module" mode="toc">

    <xsl:if test="count(key('methods',string(name)))">
		<div class="tocpart expandable" id="m_self">
	<span onclick="toc_toggle('self')">
	  <span class="toggle" id="expand_self"> + </span>
	  <span class="reduce toggle" id="reduce_self"> - </span>
	  <a href="#">Methods</a>
	</span>
	<div class="tocsubpart" id="l_self">
	  <ul>
	    <xsl:apply-templates select="key('methods',string(name))" mode="toc"/>
	  </ul>
	</div>
      </div>
    </xsl:if>

    <xsl:for-each select="methods/method[not(modulename=/page/content/module/name)]">
      <xsl:if test="generate-id()=generate-id(key('methods',modulename)[1])">
	<div class="tocpart expandable" id="m_{modulename}">
	  <span  onclick="toc_toggle('{modulename}')">
	    <span class="toggle" id="expand_{modulename}"> + </span>
	    <span class="reduce toggle" id="reduce_{modulename}"> - </span>
	    <a href="#">Methods inherited from <xsl:value-of select="modulename"/></a>
	  </span>
	  <div class="tocsubpart" id="l_{modulename}">
	    <ul>
	      <xsl:apply-templates select="key('methods',string(modulename))" mode="toc"/>
	    </ul>
	  </div>
	</div>
      </xsl:if>
    </xsl:for-each>

    <xsl:if test="specificpage">
      <div class="tocpart simple">
	<a href="#furtherInformation">Further Information</a>
      </div>
    </xsl:if>
    <br/><br/>
  </xsl:template>

  <xsl:template match="method" mode="toc">
    <li><a href="#{name}" title="{description}"><xsl:value-of select="name"/></a></li>
  </xsl:template>


</xsl:stylesheet>
