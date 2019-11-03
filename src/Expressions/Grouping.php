<?php

namespace Axiom\Ghost\Expressions;

use Axiom\Ghost\Token;
use Axiom\Ghost\Expressions\Expression;

class Grouping extends Expression
{
    /**
	 * @var Expression
	 */
	public $expression;

    /**
     * Create a new Grouping expression instance.
     * 
     * param  Expression  $expression
     */
    public function __construct(Expression $expression)
    {
        $this->expression = $expression;
    }
}